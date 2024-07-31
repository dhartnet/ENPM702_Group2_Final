#include "geometry_msgs/msg/twist.hpp"
#include "mage_msgs/action/robot_target.hpp"
#include "mage_msgs/msg/advanced_logical_camera_image.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include <iostream>
#include <map>

// // for static broadcaster
// #include "tf2_ros/static_transform_broadcaster.h"
// // for dynamic broadcaster
// #include "tf2_ros/transform_broadcaster.h"
// #include <tf2_ros/transform_listener.h>
// #include <tf2_ros/buffer.h>

// // needed for the listener
// #include <tf2_ros/transform_listener.h>
// #include <tf2_ros/buffer.h>

using namespace std::chrono_literals;
using RobotTarget = mage_msgs::action::RobotTarget;
using GoalHandle = rclcpp_action::ClientGoalHandle<RobotTarget>;

class RobotTargetClient : public rclcpp::Node {
   public:
    float x_pos_;
    explicit RobotTargetClient(const std::string& node_name)
        : Node(node_name), next_target_x_{0.1}, next_target_y_{0.1}, camera1_flag_{false}, camera2_flag_{false}, 
            camera3_flag_{false}, camera4_flag_{false}, camera5_flag_{false}, target_map_{}, camera_1_x_{}, camera_1_y_{}, 
            camera_2_x_{}, camera_2_y_{},  camera_3_x_{}, camera_3_y_{},  camera_4_x_{}, camera_4_y_{},  camera_5_x_{}, camera_5_y_{} {

        // Create a mutually exclusive callback group
        group1_ = this->create_callback_group(
            rclcpp::CallbackGroupType::MutuallyExclusive);

        

        // Create a mutually exclusive callback group
        rclcpp::SubscriptionOptions sub_option;
        group2_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        sub_option.callback_group = group2_;

        // Create a callback group for the action client
        action_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        // Create action client

        action_client_ = rclcpp_action::create_client<RobotTarget>(this, "reach_target", action_group_);

        // Initialize publisher and subscriber
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

        odom_sub_ = create_subscription<nav_msgs::msg::Odometry>(
            "/odom", 10,
            std::bind(&RobotTargetClient::odom_callback, this, std::placeholders::_1), sub_option);

        // Connect to action server
        timer_ = this->create_wall_timer(1s, std::bind(&RobotTargetClient::send_goal, this), group1_);

        camera1_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>(
            "/mage/camera1/image", rclcpp::SensorDataQoS(),
            std::bind(&RobotTargetClient::camera1_callback, this, std::placeholders::_1), sub_option);

        camera2_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>(
            "/mage/camera2/image", rclcpp::SensorDataQoS(),
            std::bind(&RobotTargetClient::camera2_callback, this, std::placeholders::_1), sub_option);

        camera3_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>(
            "/mage/camera3/image", rclcpp::SensorDataQoS(),
            std::bind(&RobotTargetClient::camera3_callback, this, std::placeholders::_1), sub_option);

        camera4_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>(
            "/mage/camera4/image", rclcpp::SensorDataQoS(),
            std::bind(&RobotTargetClient::camera4_callback, this, std::placeholders::_1), sub_option);

        camera5_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>(
            "/mage/camera5/image", rclcpp::SensorDataQoS(),
            std::bind(&RobotTargetClient::camera5_callback, this, std::placeholders::_1), sub_option);

   private:
    void send_goal();
    void goal_response_callback(std::shared_future<GoalHandle::SharedPtr> future);
    void feedback_callback(GoalHandle::SharedPtr, const std::shared_ptr<const RobotTarget::Feedback> feedback);
    void result_callback(const GoalHandle::WrappedResult& result);
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
    void camera1_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
    void camera2_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
    void camera3_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
    void camera4_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
    void camera5_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);


   private:
    rclcpp::CallbackGroup::SharedPtr action_group_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp_action::Client<RobotTarget>::SharedPtr action_client_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    // callback groups
    rclcpp::CallbackGroup::SharedPtr group1_;
    rclcpp::CallbackGroup::SharedPtr group2_;
    double next_target_x_;
    double next_target_y_;
    rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera1_sub_;
    rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera2_sub_;
    rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera3_sub_;
    rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera4_sub_;
    rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera5_sub_;
    bool camera1_flag_;
    bool camera2_flag_;
    bool camera3_flag_;
    bool camera4_flag_;
    bool camera5_flag_;
    std::unordered_map<std::string, mage_msgs::msg::RobotTarget> target_map_; // (string "camera#_color", pose)

    double camera_1_x_{};
    double camera_1_y_{};

    double camera_2_x_{};
    double camera_2_y_{};

    double camera_3_x_{};
    double camera_3_y_{};

    double camera_4_x_{};
    double camera_4_y_{};

    double camera_5_x_{};
    double camera_5_y_{};

};
};