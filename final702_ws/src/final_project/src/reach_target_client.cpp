#include <rclcpp/executors.hpp>
#include <rclcpp/rclcpp.hpp>

#include "mage_msgs/msg/advanced_logical_camera_image.hpp"
#include "reach_target_action.hpp"

#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include "geometry_msgs/msg/pose.hpp"

#include "broadcaster_demo.hpp"
#include "listener_demo.hpp"

void RobotTargetClient::send_goal() {
    auto goal_msg = RobotTarget::Goal();

    goal_msg.target.x = next_target_x_;
    goal_msg.target.y = next_target_y_;
    RCLCPP_INFO_STREAM(this->get_logger(), "Sending goal x[" << goal_msg.target.x << "], y[" << goal_msg.target.y << "]");
    auto goal_options = rclcpp_action::Client<RobotTarget>::SendGoalOptions();
    goal_options.goal_response_callback = std::bind(&RobotTargetClient::goal_response_callback, this, std::placeholders::_1);
    goal_options.feedback_callback = std::bind(&RobotTargetClient::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);
    goal_options.result_callback = std::bind(&RobotTargetClient::result_callback, this, std::placeholders::_1);

    auto goal_handle_future = action_client_->async_send_goal(goal_msg, goal_options);
}

void RobotTargetClient::goal_response_callback(std::shared_future<GoalHandle::SharedPtr> future) {
    auto goal_handle = future.get();
    if (!goal_handle) {
        RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
    } else {
        RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result...");
    }
}

void RobotTargetClient::feedback_callback(GoalHandle::SharedPtr, const std::shared_ptr<const RobotTarget::Feedback> feedback) {
    RCLCPP_INFO(this->get_logger(), "Received feedback: distance to goal = %f", feedback->distance_to_goal);

    if (feedback->distance_to_goal < 0.04) {
        RCLCPP_INFO(this->get_logger(), "New goal");
        next_target_x_ = 10.0;
        next_target_y_ = 10.0;
    }
}

void RobotTargetClient::result_callback(const GoalHandle::WrappedResult& result) {
    if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
        RCLCPP_INFO(this->get_logger(), ">>>>>>>>Goal succeeded: %s", result.result->message.c_str());
    } else if (result.code == rclcpp_action::ResultCode::ABORTED) {
        RCLCPP_ERROR(this->get_logger(), ">>>>>>>>Goal was aborted");
    } else {
        RCLCPP_ERROR(this->get_logger(), ">>>>>>>>Unknown result code");
    }
}

void RobotTargetClient::odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
    // Process odometry data if needed
    RCLCPP_INFO_STREAM(this->get_logger(), "Current position: x[" << msg->pose.pose.position.x << "], y[" << msg->pose.pose.position.y << "]");
}

void RobotTargetClient::camera1_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
    
    // Flag to ensure data is only gathered and inserted into map once
    if (!camera1_flag_){
        RCLCPP_INFO(this->get_logger(), "Camera1 callback triggered");

        // empty data check
        if (msg->part_poses.empty()) {
            RCLCPP_WARN(this->get_logger(), "No parts detected");
            return;
        }

        // Extract pose and orientation positions of object w/respect to camera
        mage_msgs::msg::RobotTarget part;
        auto part_pose = msg->part_poses[0].pose;
        part.pose_x = part_pose.position.x;
        part.pose_y = part_pose.position.y;
        part.pose_z = part_pose.position.z;

        part.quat_x = part_pose.orientation.x;
        part.quat_y = part_pose.orientation.y;
        part.quat_z = part_pose.orientation.z;
        part.quat_w = part_pose.orientation.w;

        // Extract color information for object from camera and check what color it is
        auto part_color = msg->part_poses[0].part.color;
        std::string part_string_color;

        if (part_color == msg->part_poses[0].part.color.RED){
            part_string_color = "red"; }

        else if (part_color == msg->part_poses[0].part.color.GREEN){
            part_string_color = "green"; }
        
        else if (part_color == msg->part_poses[0].part.color.BLUE){
            part_string_color = "blue"; }

        else if (part_color == msg->part_poses[0].part.color.ORANGE){
            part_string_color = "orange"; }

        else if (part_color == msg->part_poses[0].part.color.PURPLE){
            part_string_color = "purple"; }

        // Insert data into map
        // {key, (data pair)} = {<string> camera#_frame, (<string> color, <RobotTarget> pose/orientation data)}
        target_map_.insert({"camera1_frame", (part_string_color, part)});

        RCLCPP_INFO(this->get_logger(), "Object in camera 1 FOV is at: [x: %f, y: %f]", camera_x, camera_y);

        // Set flag to TRUE when data has been inserted into map so duplicate data isn't continously added
        camera1_flag_ = true;

        }
    }

void RobotTargetClient::camera2_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
    // Flag to ensure data is only gathered and inserted into map once
    if (!camera2_flag_){
        RCLCPP_INFO(this->get_logger(), "Camera2 callback triggered");

        // empty data check
        if (msg->part_poses.empty()) {
            RCLCPP_WARN(this->get_logger(), "No parts detected");
            return;
        }

        // Extract pose and orientation positions of object w/respect to camera
        mage_msgs::msg::RobotTarget part;
        auto part_pose = msg->part_poses[0].pose;
        part.pose_x = part_pose.position.x;
        part.pose_y = part_pose.position.y;
        part.pose_z = part_pose.position.z;

        part.quat_x = part_pose.orientation.x;
        part.quat_y = part_pose.orientation.y;
        part.quat_z = part_pose.orientation.z;
        part.quat_w = part_pose.orientation.w;

        // Extract color information for object from camera and check what color it is
        auto part_color = msg->part_poses[0].part.color;
        std::string part_string_color;

        if (part_color == msg->part_poses[0].part.color.RED){
            part_string_color = "red"; }

        else if (part_color == msg->part_poses[0].part.color.GREEN){
            part_string_color = "green"; }
        
        else if (part_color == msg->part_poses[0].part.color.BLUE){
            part_string_color = "blue"; }

        else if (part_color == msg->part_poses[0].part.color.ORANGE){
            part_string_color = "orange"; }

        else if (part_color == msg->part_poses[0].part.color.PURPLE){
            part_string_color = "purple"; }

        // Insert data into map
        // {key, (data pair)} = {<string> camera#_frame, (<string> color, <RobotTarget> pose/orientation data)}
        target_map_.insert({"camera2_frame", (part_string_color, part)});

        RCLCPP_INFO(this->get_logger(), "Object in camera 2 FOV is at: [x: %f, y: %f]", camera_x, camera_y);

        // Set flag to TRUE when data has been inserted into map so duplicate data isn't continously added
        camera2_flag_ = true;

    }
}

void RobotTargetClient::camera3_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
    // Flag to ensure data is only gathered and inserted into map once
    if (!camera3_flag_){
        RCLCPP_INFO(this->get_logger(), "Camera3 callback triggered");

        // empty data check
        if (msg->part_poses.empty()) {
            RCLCPP_WARN(this->get_logger(), "No parts detected");
            return;
        }

        // Extract pose and orientation positions of object w/respect to camera
        mage_msgs::msg::RobotTarget part;
        auto part_pose = msg->part_poses[0].pose;
        part.pose_x = part_pose.position.x;
        part.pose_y = part_pose.position.y;
        part.pose_z = part_pose.position.z;

        part.quat_x = part_pose.orientation.x;
        part.quat_y = part_pose.orientation.y;
        part.quat_z = part_pose.orientation.z;
        part.quat_w = part_pose.orientation.w;

        // Extract color information for object from camera and check what color it is
        auto part_color = msg->part_poses[0].part.color;
        std::string part_string_color;

        if (part_color == msg->part_poses[0].part.color.RED){
            part_string_color = "red"; }

        else if (part_color == msg->part_poses[0].part.color.GREEN){
            part_string_color = "green"; }
        
        else if (part_color == msg->part_poses[0].part.color.BLUE){
            part_string_color = "blue"; }

        else if (part_color == msg->part_poses[0].part.color.ORANGE){
            part_string_color = "orange"; }

        else if (part_color == msg->part_poses[0].part.color.PURPLE){
            part_string_color = "purple"; }

        // Insert data into map
        // {key, (data pair)} = {<string> camera#_frame, (<string> color, <RobotTarget> pose/orientation data)}
        target_map_.insert({"camera3_frame", (part_string_color, part)});

        RCLCPP_INFO(this->get_logger(), "Object in camera 3 FOV is at: [x: %f, y: %f]", camera_x, camera_y);

        // Set flag to TRUE when data has been inserted into map so duplicate data isn't continously added
        camera3_flag_ = true;

    }
}

void RobotTargetClient::camera4_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
    // Flag to ensure data is only gathered and inserted into map once
    if (!camera4_flag_){
        RCLCPP_INFO(this->get_logger(), "Camera4 callback triggered");

        // empty data check
        if (msg->part_poses.empty()) {
            RCLCPP_WARN(this->get_logger(), "No parts detected");
            return;
        }

        // Extract pose and orientation positions of object w/respect to camera
        mage_msgs::msg::RobotTarget part;
        auto part_pose = msg->part_poses[0].pose;
        part.pose_x = part_pose.position.x;
        part.pose_y = part_pose.position.y;
        part.pose_z = part_pose.position.z;

        part.quat_x = part_pose.orientation.x;
        part.quat_y = part_pose.orientation.y;
        part.quat_z = part_pose.orientation.z;
        part.quat_w = part_pose.orientation.w;

        // Extract color information for object from camera and check what color it is
        auto part_color = msg->part_poses[0].part.color;
        std::string part_string_color;

        if (part_color == msg->part_poses[0].part.color.RED){
            part_string_color = "red"; }

        else if (part_color == msg->part_poses[0].part.color.GREEN){
            part_string_color = "green"; }
        
        else if (part_color == msg->part_poses[0].part.color.BLUE){
            part_string_color = "blue"; }

        else if (part_color == msg->part_poses[0].part.color.ORANGE){
            part_string_color = "orange"; }

        else if (part_color == msg->part_poses[0].part.color.PURPLE){
            part_string_color = "purple"; }

        // Insert data into map
        // {key, (data pair)} = {<string> camera#_frame, (<string> color, <RobotTarget> pose/orientation data)}
        target_map_.insert({"camera4_frame", (part_string_color, part)});

        RCLCPP_INFO(this->get_logger(), "Object in camera 4 FOV is at: [x: %f, y: %f]", camera_x, camera_y);

        // Set flag to TRUE when data has been inserted into map so duplicate data isn't continously added
        camera4_flag_ = true;

    }
}

void RobotTargetClient::camera5_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
    // Flag to ensure data is only gathered and inserted into map once
    if (!camera5_flag_){
        RCLCPP_INFO(this->get_logger(), "Camera5 callback triggered");

        // empty data check
        if (msg->part_poses.empty()) {
            RCLCPP_WARN(this->get_logger(), "No parts detected");
            return;
        }

        // Extract pose and orientation positions of object w/respect to camera
        mage_msgs::msg::RobotTarget part;
        auto part_pose = msg->part_poses[0].pose;
        part.pose_x = part_pose.position.x;
        part.pose_y = part_pose.position.y;
        part.pose_z = part_pose.position.z;

        part.quat_x = part_pose.orientation.x;
        part.quat_y = part_pose.orientation.y;
        part.quat_z = part_pose.orientation.z;
        part.quat_w = part_pose.orientation.w;

        // Extract color information for object from camera and check what color it is
        auto part_color = msg->part_poses[0].part.color;
        std::string part_string_color;

        if (part_color == msg->part_poses[0].part.color.RED){
            part_string_color = "red"; }

        else if (part_color == msg->part_poses[0].part.color.GREEN){
            part_string_color = "green"; }
        
        else if (part_color == msg->part_poses[0].part.color.BLUE){
            part_string_color = "blue"; }

        else if (part_color == msg->part_poses[0].part.color.ORANGE){
            part_string_color = "orange"; }

        else if (part_color == msg->part_poses[0].part.color.PURPLE){
            part_string_color = "purple"; }

        // Insert data into map
        // {key, (data pair)} = {<string> camera#_frame, (<string> color, <RobotTarget> pose/orientation data)}
        target_map_.insert({"camera5_frame", (part_string_color, part)});

        RCLCPP_INFO(this->get_logger(), "Object in camera 5 FOV is at: [x: %f, y: %f]", camera_x, camera_y);

        // Set flag to TRUE when data has been inserted into map so duplicate data isn't continously added
        camera5_flag_ = true;

    }
}

// BROADCASTER and LISTENER

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);

    auto node =
        std::make_shared<RobotTargetClient>("robot_target_client");
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();  // This will start the execution
    rclcpp::shutdown();
}
