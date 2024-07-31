#include <rclcpp/executors.hpp>
#include <rclcpp/rclcpp.hpp>

#include "mage_msgs/msg/advanced_logical_camera_image.hpp"
#include "reach_target_action.hpp"

#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include "geometry_msgs/msg/pose.hpp"

#include "broadcaster_demo.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <utils.hpp>
// needed for the listener
#include <tf2/exceptions.h>
#include "listener_demo.hpp"
#include <rclcpp/rclcpp.hpp>
#include <listener_demo.hpp>
#include <geometry_msgs/msg/pose.hpp> // look into this 


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
            part.color = "red"; 
            // part_string_color = "red"; 
            }

        else if (part_color == msg->part_poses[0].part.color.GREEN){
            part.color = "green";
            // part_string_color = "green"; 
            }
        
        else if (part_color == msg->part_poses[0].part.color.BLUE){
            part.color = "blue";
            // part_string_color = "blue"; 
            }

        else if (part_color == msg->part_poses[0].part.color.ORANGE){
            part.color = "orange";
            // part_string_color = "orange"; 
            }

        else if (part_color == msg->part_poses[0].part.color.PURPLE){
            part.color = "purple";
            // part_string_color = "purple"; 
            }

        // Insert data into map
        // {key, (data pair)} = {<string> camera#_frame, (<string> color, <RobotTarget> pose/orientation data)}
        target_map_.insert({"camera1", part});

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
        target_map_.insert({"camera2", (part_string_color, part)});

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
        target_map_.insert({"camera3", (part_string_color, part)});

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
        target_map_.insert({"camera4", (part_string_color, part)});

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
        target_map_.insert({"camera5", (part_string_color, part)});

        RCLCPP_INFO(this->get_logger(), "Object in camera 5 FOV is at: [x: %f, y: %f]", camera_x, camera_y);

        // Set flag to TRUE when data has been inserted into map so duplicate data isn't continously added
        camera5_flag_ = true;

    }
}

// BROADCASTER
using namespace std::chrono_literals;

void BroadcasterDemo::static_broadcast_timer_cb_()
{
    geometry_msgs::msg::TransformStamped static_transform_stamped; // need to make unique variable names?
    /////////////////////////////////////////////////
    // First camera frame
    /////////////////////////////////////////////////
    // get value from map using key
    auto camera1_map_value = target_map_.at("camera1");

    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "camera1_frame";
    static_transform_stamped.child_frame_id = "camera1_part";
    // need to add subscriber to get this info
    static_transform_stamped.transform.translation.x = camera1_map_value.pose_x; //get values from map using RobotTarget msg type
    static_transform_stamped.transform.translation.y = camera1_map_value.pose_y;
    static_transform_stamped.transform.translation.z = camera1_map_value.pose_z;

    // geometry_msgs::msg::Quaternion quaternion = utils_ptr_->set_quaternion_from_euler(M_PI / 2, M_PI / 3, M_PI / 4);
    static_transform_stamped.transform.rotation.x = camera1_map_value.quat_x;
    static_transform_stamped.transform.rotation.y = camera1_map_value.quat_y;
    static_transform_stamped.transform.rotation.z = camera1_map_value.quat_z;
    static_transform_stamped.transform.rotation.w = camera1_map_value.quat_w;
    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);

    /////////////////////////////////////////////////
    // Second frame
    /////////////////////////////////////////////////
    auto camera2_map_value = target_map_.at("camera2_frame");
    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "world";
    static_transform_stamped.child_frame_id = "camera2_frame";

    static_transform_stamped.transform.translation.x = camera2_map_value.pose_x;
    static_transform_stamped.transform.translation.y = camera2_map_value.pose_y;
    static_transform_stamped.transform.translation.z = camera2_map_value.pose_z;

    // geometry_msgs::msg::Quaternion quaternion = utils_ptr_->set_quaternion_from_euler(M_PI / 2, M_PI / 3, M_PI / 4);
    static_transform_stamped.transform.rotation.x = camera2_map_value.quat_x;
    static_transform_stamped.transform.rotation.y = camera2_map_value.quat_y;
    static_transform_stamped.transform.rotation.z = camera2_map_value.quat_z;
    static_transform_stamped.transform.rotation.w = camera2_map_value.quat_w;
    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);

        /////////////////////////////////////////////////
    // third frame
    /////////////////////////////////////////////////
    auto camera3_map_value = target_map_.at("camera3_frame");
    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "world";
    static_transform_stamped.child_frame_id = "camera3_frame";

    static_transform_stamped.transform.translation.x = camera3_map_value.pose_x;
    static_transform_stamped.transform.translation.y = camera3_map_value.pose_y;
    static_transform_stamped.transform.translation.z = camera3_map_value.pose_z;

    // geometry_msgs::msg::Quaternion quaternion = utils_ptr_->set_quaternion_from_euler(M_PI / 2, M_PI / 3, M_PI / 4);
    static_transform_stamped.transform.rotation.x = camera3_map_value.quat_x;
    static_transform_stamped.transform.rotation.y = camera3_map_value.quat_y;
    static_transform_stamped.transform.rotation.z = camera3_map_value.quat_z;
    static_transform_stamped.transform.rotation.w = camera3_map_value.quat_w;
    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);

    /////////////////////////////////////////////////
    // fourth frame
    /////////////////////////////////////////////////
    auto camera4_map_value = target_map_.at("camera4_frame");
    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "world";
    static_transform_stamped.child_frame_id = "camera4_frame";

    static_transform_stamped.transform.translation.x = camera4_map_value.pose_x;
    static_transform_stamped.transform.translation.y = camera4_map_value.pose_y;
    static_transform_stamped.transform.translation.z = camera4_map_value.pose_z;

    // geometry_msgs::msg::Quaternion quaternion = utils_ptr_->set_quaternion_from_euler(M_PI / 2, M_PI / 3, M_PI / 4);
    static_transform_stamped.transform.rotation.x = camera4_map_value.quat_x;
    static_transform_stamped.transform.rotation.y = camera4_map_value.quat_y;
    static_transform_stamped.transform.rotation.z = camera4_map_value.quat_z;
    static_transform_stamped.transform.rotation.w = camera4_map_value.quat_w;
    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);

    /////////////////////////////////////////////////
    // Fifth frame
    /////////////////////////////////////////////////
    auto camera5_map_value = target_map_.at("camera5_frame");
    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "world";
    static_transform_stamped.child_frame_id = "camera5_frame";

    static_transform_stamped.transform.translation.x = camera5_map_value.pose_x;
    static_transform_stamped.transform.translation.y = camera5_map_value.pose_y;
    static_transform_stamped.transform.translation.z = camera5_map_value.pose_z;

    // geometry_msgs::msg::Quaternion quaternion = utils_ptr_->set_quaternion_from_euler(M_PI / 2, M_PI / 3, M_PI / 4);
    static_transform_stamped.transform.rotation.x = camera5_map_value.quat_x;
    static_transform_stamped.transform.rotation.y = camera5_map_value.quat_y;
    static_transform_stamped.transform.rotation.z = camera5_map_value.quat_z;
    static_transform_stamped.transform.rotation.w = camera5_map_value.quat_w;
    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);
} //End Broadcaster

// LISTENER
using namespace std::chrono_literals;

void ListenerDemo::listen_transform(const std::string &source_frame, const std::string &target_frame)
{
    geometry_msgs::msg::TransformStamped t_stamped;
    geometry_msgs::msg::Pose pose_out_1;
    geometry_msgs::msg::Pose pose_out_2;
    geometry_msgs::msg::Pose pose_out_3;
    geometry_msgs::msg::Pose pose_out_4;
    geometry_msgs::msg::Pose pose_out_5;

    try
    {
        t_stamped = tf_buffer_->lookupTransform(source_frame, target_frame, tf2::TimePointZero, 50ms);
    }
    catch (const tf2::TransformException &ex)
    {
        RCLCPP_ERROR_STREAM(this->get_logger(), "Could not get transform between " << source_frame << " and " << target_frame << ": " << ex.what());
        return;
    }

    pose_out.position.x = t_stamped.transform.translation.x;
    pose_out.position.y = t_stamped.transform.translation.y;
    // pose_out.position.z = t_stamped.transform.translation.z;
    // pose_out.orientation = t_stamped.transform.rotation;

    RCLCPP_INFO_STREAM(this->get_logger(), target_frame << " in " << source_frame << ":\n"
                                                        << "x: " << pose_out.position.x << "\t"
                                                        << "y: " << pose_out.position.y << "\t"
                                                        // << "z: " << pose_out.position.z << "\n"
                                                        // << "qx: " << pose_out.orientation.x << "\t"
                                                        // << "qy: " << pose_out.orientation.y << "\t"
                                                        // << "qz: " << pose_out.orientation.z << "\t"
                                                        // << "qw: " << pose_out.orientation.w << "\n");
}

void ListenerDemo::listen_timer_cb_()
{
    listen_transform("camera1_part", "world");
    listen_transform("camera2_part", "world");
    listen_transform("camera3_part", "world");
    listen_transform("camera4_part", "world");
    listen_transform("camera5_part", "world");
    // 5 X need to send info to reach target by creating topics this can publish to, the reach taget subscriber will subscribe to this. 

} //End Listener

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);

    auto node =
        std::make_shared<RobotTargetClient>("robot_target_client");
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();  // This will start the execution
    rclcpp::shutdown();
}
