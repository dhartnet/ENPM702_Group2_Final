#include <rclcpp/executors.hpp>
#include <rclcpp/rclcpp.hpp>

#include "mage_msgs/msg/advanced_logical_camera_image.hpp"
#include "mage_msgs/msg/part.hpp"
#include "reach_target_action.hpp"

#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include "geometry_msgs/msg/pose.hpp"

#include "geometry_msgs/msg/transform_stamped.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <utils.hpp>
// needed for the listener
#include <tf2/exceptions.h>

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

        // Create variable to hold the camera number
        std::string camera{};

        // Loop through the map of waypoints one at a time to extract the color of the desired waypoints in order
        for (auto i = waypoint_colors_.begin(); i != waypoint_colors_.end(); ++i) {
            auto waypoint_color = i->second; // variable to store waypoint color (String)

            // linear search through map containing data from each camera by value (not key), searching until the color of the desired waypoint is found
            for (auto j = target_map_.begin(); j != target_map_.end(); ++j) {
                auto part_data = j->second; // variable storing data from camera
                
                // If desired color is found, use associated camera number to then assign proper (x,y) coordinate attributes to the next_target_x/y_ attribute
                if (part_data.color == waypoint_color) {
                    camera = j->first; // variable stores string name of camera

                    // Use camera number to assign proper coordinate attributes to be the next target coordinate
                    if (camera == "camera1") {
                        next_target_x_ = camera_1_x_;
                        next_target_y_ = camera_1_y_; }

                    else if (camera == "camera2") {
                        next_target_x_ = camera_2_x_;
                        next_target_y_ = camera_2_y_; }

                    else if (camera == "camera3") {
                        next_target_x_ = camera_3_x_;
                        next_target_y_ = camera_3_y_; }

                    else if (camera == "camera4") {
                        next_target_x_ = camera_4_x_;
                        next_target_y_ = camera_4_y_; }

                    else if (camera == "camera5") {
                        next_target_x_ = camera_5_x_;
                        next_target_y_ = camera_5_y_; }
                }
            }
            
        }
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

// Camera callback function to retrieve and store camera data
//*******Comments in this camera callback function apply the same to all five camera callbacks below*******//
void RobotTargetClient::camera1_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
    
    // Flag to ensure data is only gathered and inserted into map once
    if (!camera1_flag_){
        RCLCPP_INFO(this->get_logger(), "Camera1 callback triggered");

        // Check to ensure data isn't empty
        if (msg->part_poses.empty()) {
            RCLCPP_WARN(this->get_logger(), "No parts detected");
            return;
        }

        // Extract pose and orientation positions of object w/respect to camera
        // "part" is the variable we use to store the camera data from part_poses[0].pose
        // "part" is of type mage_msgs::msg::RobotTarget
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
        // Assign color to "part"
        auto part_color = msg->part_poses[0].part.color;

        if (part_color == mage_msgs::msg::Part::RED) {
            part.color = "red"; }

        else if (part_color == mage_msgs::msg::Part::GREEN){
            part.color = "green";}
        
        else if (part_color == mage_msgs::msg::Part::BLUE){
            part.color = "blue";}

        else if (part_color == mage_msgs::msg::Part::ORANGE){
            part.color = "orange";}

        else if (part_color == mage_msgs::msg::Part::PURPLE){
            part.color = "purple";}

        // Insert "part" data into a map as the value. The key is the camera number
        // {key, value} = {<std::string> camera#_frame, <mage_msgs::msg::RobotTarget> color/pose/orientation data}
        target_map_.insert({"camera1", part});

        // Set flag to TRUE when data has been inserted into map so duplicate data isn't continously added
        camera1_flag_ = true;
        }
    }

void RobotTargetClient::camera2_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {

    if (!camera2_flag_){
        RCLCPP_INFO(this->get_logger(), "Camera2 callback triggered");

        if (msg->part_poses.empty()) {
            RCLCPP_WARN(this->get_logger(), "No parts detected");
            return;
        }

        mage_msgs::msg::RobotTarget part;
        auto part_pose = msg->part_poses[0].pose;
        part.pose_x = part_pose.position.x;
        part.pose_y = part_pose.position.y;
        part.pose_z = part_pose.position.z;

        part.quat_x = part_pose.orientation.x;
        part.quat_y = part_pose.orientation.y;
        part.quat_z = part_pose.orientation.z;
        part.quat_w = part_pose.orientation.w;

        auto part_color = msg->part_poses[0].part.color;

        if (part_color == mage_msgs::msg::Part::RED) {
            part.color = "red"; }

        else if (part_color == mage_msgs::msg::Part::GREEN){
            part.color = "green";}
        
        else if (part_color == mage_msgs::msg::Part::BLUE){
            part.color = "blue";}

        else if (part_color == mage_msgs::msg::Part::ORANGE){
            part.color = "orange";}

        else if (part_color == mage_msgs::msg::Part::PURPLE){
            part.color = "purple";}

        target_map_.insert({"camera2", part});

        camera2_flag_ = true;
    }
}

void RobotTargetClient::camera3_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {

    if (!camera3_flag_){
        RCLCPP_INFO(this->get_logger(), "Camera3 callback triggered");

        if (msg->part_poses.empty()) {
            RCLCPP_WARN(this->get_logger(), "No parts detected");
            return;
        }

        mage_msgs::msg::RobotTarget part;
        auto part_pose = msg->part_poses[0].pose;
        part.pose_x = part_pose.position.x;
        part.pose_y = part_pose.position.y;
        part.pose_z = part_pose.position.z;

        part.quat_x = part_pose.orientation.x;
        part.quat_y = part_pose.orientation.y;
        part.quat_z = part_pose.orientation.z;
        part.quat_w = part_pose.orientation.w;

        auto part_color = msg->part_poses[0].part.color;

        if (part_color == mage_msgs::msg::Part::RED) {
            part.color = "red"; }

        else if (part_color == mage_msgs::msg::Part::GREEN){
            part.color = "green";}
        
        else if (part_color == mage_msgs::msg::Part::BLUE){
            part.color = "blue";}

        else if (part_color == mage_msgs::msg::Part::ORANGE){
            part.color = "orange";}

        else if (part_color == mage_msgs::msg::Part::PURPLE){
            part.color = "purple";}

        target_map_.insert({"camera3", part});

        camera3_flag_ = true;
    }
}

void RobotTargetClient::camera4_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {

    if (!camera4_flag_){
        RCLCPP_INFO(this->get_logger(), "Camera4 callback triggered");

        if (msg->part_poses.empty()) {
            RCLCPP_WARN(this->get_logger(), "No parts detected");
            return;
        }

        mage_msgs::msg::RobotTarget part;
        auto part_pose = msg->part_poses[0].pose;
        part.pose_x = part_pose.position.x;
        part.pose_y = part_pose.position.y;
        part.pose_z = part_pose.position.z;

        part.quat_x = part_pose.orientation.x;
        part.quat_y = part_pose.orientation.y;
        part.quat_z = part_pose.orientation.z;
        part.quat_w = part_pose.orientation.w;

        auto part_color = msg->part_poses[0].part.color;

        if (part_color == mage_msgs::msg::Part::RED) {
            part.color = "red"; }

        else if (part_color == mage_msgs::msg::Part::GREEN){
            part.color = "green";}
        
        else if (part_color == mage_msgs::msg::Part::BLUE){
            part.color = "blue";}

        else if (part_color == mage_msgs::msg::Part::ORANGE){
            part.color = "orange";}

        else if (part_color == mage_msgs::msg::Part::PURPLE){
            part.color = "purple";}

        target_map_.insert({"camera4", part});

        camera4_flag_ = true;
    }
}

void RobotTargetClient::camera5_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {

    if (!camera5_flag_){
        RCLCPP_INFO(this->get_logger(), "Camera5 callback triggered");

        if (msg->part_poses.empty()) {
            RCLCPP_WARN(this->get_logger(), "No parts detected");
            return;
        }

        mage_msgs::msg::RobotTarget part;
        auto part_pose = msg->part_poses[0].pose;
        part.pose_x = part_pose.position.x;
        part.pose_y = part_pose.position.y;
        part.pose_z = part_pose.position.z;

        part.quat_x = part_pose.orientation.x;
        part.quat_y = part_pose.orientation.y;
        part.quat_z = part_pose.orientation.z;
        part.quat_w = part_pose.orientation.w;

        auto part_color = msg->part_poses[0].part.color;

        if (part_color == mage_msgs::msg::Part::RED) {
            part.color = "red"; }

        else if (part_color == mage_msgs::msg::Part::GREEN){
            part.color = "green";}
        
        else if (part_color == mage_msgs::msg::Part::BLUE){
            part.color = "blue";}

        else if (part_color == mage_msgs::msg::Part::ORANGE){
            part.color = "orange";}

        else if (part_color == mage_msgs::msg::Part::PURPLE){
            part.color = "purple";}

        target_map_.insert({"camera5", part});

        camera5_flag_ = true;
    }
}

// Broadcaster for coordinate transforms
using namespace std::chrono_literals;

void RobotTargetClient::static_broadcast_timer_cb_() {

    geometry_msgs::msg::TransformStamped static_transform_stamped;

    /////////////////////////////////////////////////
    // First frame (camera 1)
    /////////////////////////////////////////////////

    // Get value (camera data) from map using key
    auto camera1_map_value = target_map_.at("camera1");

    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "camera1_frame";
    static_transform_stamped.child_frame_id = "camera1_part";

    // Assign values from map data to the transform data
    static_transform_stamped.transform.translation.x = camera1_map_value.pose_x;
    static_transform_stamped.transform.translation.y = camera1_map_value.pose_y;
    static_transform_stamped.transform.translation.z = camera1_map_value.pose_z;

    static_transform_stamped.transform.rotation.x = camera1_map_value.quat_x;
    static_transform_stamped.transform.rotation.y = camera1_map_value.quat_y;
    static_transform_stamped.transform.rotation.z = camera1_map_value.quat_z;
    static_transform_stamped.transform.rotation.w = camera1_map_value.quat_w;

    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);

    /////////////////////////////////////////////////
    // Second frame (camera 2)
    /////////////////////////////////////////////////

    // Get value (camera data) from map using key
    auto camera2_map_value = target_map_.at("camera2");

    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "camera2_frame";
    static_transform_stamped.child_frame_id = "camera2_part";

    // Assign values from map data to the transform data
    static_transform_stamped.transform.translation.x = camera2_map_value.pose_x;
    static_transform_stamped.transform.translation.y = camera2_map_value.pose_y;
    static_transform_stamped.transform.translation.z = camera2_map_value.pose_z;

    static_transform_stamped.transform.rotation.x = camera2_map_value.quat_x;
    static_transform_stamped.transform.rotation.y = camera2_map_value.quat_y;
    static_transform_stamped.transform.rotation.z = camera2_map_value.quat_z;
    static_transform_stamped.transform.rotation.w = camera2_map_value.quat_w;

    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);

    /////////////////////////////////////////////////
    // Third frame (camera 3)
    /////////////////////////////////////////////////

    // Get value (camera data) from map using key
    auto camera3_map_value = target_map_.at("camera3");

    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "camera3_frame";
    static_transform_stamped.child_frame_id = "camera3_part";

    // Assign values from map data to the transform data
    static_transform_stamped.transform.translation.x = camera3_map_value.pose_x;
    static_transform_stamped.transform.translation.y = camera3_map_value.pose_y;
    static_transform_stamped.transform.translation.z = camera3_map_value.pose_z;

    static_transform_stamped.transform.rotation.x = camera3_map_value.quat_x;
    static_transform_stamped.transform.rotation.y = camera3_map_value.quat_y;
    static_transform_stamped.transform.rotation.z = camera3_map_value.quat_z;
    static_transform_stamped.transform.rotation.w = camera3_map_value.quat_w;

    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);

    /////////////////////////////////////////////////
    // Fourth frame (camera 4)
    /////////////////////////////////////////////////

    // Get value (camera data) from map using key
    auto camera4_map_value = target_map_.at("camera4");
    
    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "camera4_frame";
    static_transform_stamped.child_frame_id = "camera4_part";

    // Assign values from map data to the transform data
    static_transform_stamped.transform.translation.x = camera4_map_value.pose_x;
    static_transform_stamped.transform.translation.y = camera4_map_value.pose_y;
    static_transform_stamped.transform.translation.z = camera4_map_value.pose_z;

    static_transform_stamped.transform.rotation.x = camera4_map_value.quat_x;
    static_transform_stamped.transform.rotation.y = camera4_map_value.quat_y;
    static_transform_stamped.transform.rotation.z = camera4_map_value.quat_z;
    static_transform_stamped.transform.rotation.w = camera4_map_value.quat_w;

    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);

    /////////////////////////////////////////////////
    // Fifth frame (camera 5)
    /////////////////////////////////////////////////

    // Get value (camera data) from map using key
    auto camera5_map_value = target_map_.at("camera5");

    static_transform_stamped.header.stamp = this->get_clock()->now();
    static_transform_stamped.header.frame_id = "camera5_frame";
    static_transform_stamped.child_frame_id = "camera5_part";

    // Assign values from map data to the transform data
    static_transform_stamped.transform.translation.x = camera5_map_value.pose_x;
    static_transform_stamped.transform.translation.y = camera5_map_value.pose_y;
    static_transform_stamped.transform.translation.z = camera5_map_value.pose_z;

    static_transform_stamped.transform.rotation.x = camera5_map_value.quat_x;
    static_transform_stamped.transform.rotation.y = camera5_map_value.quat_y;
    static_transform_stamped.transform.rotation.z = camera5_map_value.quat_z;
    static_transform_stamped.transform.rotation.w = camera5_map_value.quat_w;

    // Send the transform
    tf_static_broadcaster_->sendTransform(static_transform_stamped);
} //End Broadcaster

// Listener for coordinate transforms
using namespace std::chrono_literals;

void RobotTargetClient::listen_transform(const std::string &source_frame, const std::string &target_frame)
{
    geometry_msgs::msg::TransformStamped t_stamped;
    geometry_msgs::msg::Pose pose_out;

    // Check for empty/incomplete frame transforms
    try
    {
        t_stamped = tf_buffer_->lookupTransform(source_frame, target_frame, tf2::TimePointZero, 50ms);
    }
    catch (const tf2::TransformException &ex)
    {
        RCLCPP_ERROR_STREAM(this->get_logger(), "Could not get transform between " << source_frame << " and " << target_frame << ": " << ex.what());
        return;
    }

    // Local variables that hold (x,y) coordinates from transform broadcaster
    pose_out.position.x = t_stamped.transform.translation.x;
    pose_out.position.y = t_stamped.transform.translation.y;

    // Check the source frame to determine what camera the data was broadcasted from
    // Assign (x,y) coordinates to proper (x,y) attributes associated with the camera
    // Attributes are to be used by "feedback_callback" to send coordinates to the robot 
    if (source_frame == "camera1_frame") {
        camera_1_x_ = pose_out.position.x;
        camera_1_y_ = pose_out.position.y; }
    
    else if (source_frame == "camera2_frame") {
        camera_2_x_ = pose_out.position.x;
        camera_2_y_ = pose_out.position.y; }

    else if (source_frame == "camera3_frame") {
        camera_3_x_ = pose_out.position.x;
        camera_3_y_ = pose_out.position.y; }

    else if (source_frame == "camera4_frame") {
        camera_4_x_ = pose_out.position.x;
        camera_4_y_ = pose_out.position.y; }

    else if (source_frame == "camera5_frame") {
        camera_5_x_ = pose_out.position.x;
        camera_5_y_ = pose_out.position.y; }

    // Print target frame
    RCLCPP_INFO_STREAM(this->get_logger(), target_frame << " in " << source_frame << ":\n"
                                                        << "x: " << pose_out.position.x << "\t"
                                                        << "y: " << pose_out.position.y << "\t");
}

// Timer callback used with listener for transforms
void RobotTargetClient::listen_timer_cb_()
{
    // Call transform for each camera to transform camera coordintes to the world frame so the robot can use them
    listen_transform("camera1_part", "world");
    listen_transform("camera2_part", "world");
    listen_transform("camera3_part", "world");
    listen_transform("camera4_part", "world");
    listen_transform("camera5_part", "world");

} //End Listener

// Main function
int main(int argc, char** argv) {
    rclcpp::init(argc, argv);

    auto node =
        std::make_shared<RobotTargetClient>("robot_target_client");
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();  // This will start the execution
    rclcpp::shutdown();
}
