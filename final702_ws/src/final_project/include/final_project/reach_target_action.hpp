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
            camera3_flag_{false}, camera4_flag_{false}, camera5_flag_{false}, target_map_{}, camera_1_x{}, camera_1_y{}, 
            camera_2_x{}, camera_2_y{},  camera_3_x{}, camera_3_y{},  camera_4_x{}, camera_4_y{},  camera_5_x{}, camera_5_y{} {

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
           
        //  // Added for broadcaster
        //  // parameter to decide whether to execute the broadcaster or not
        // RCLCPP_INFO(this->get_logger(), "Broadcaster demo started");

        // // initialize a static transform broadcaster
        // tf_static_broadcaster_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);

        // // initialize the transform broadcaster
        // tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);

        // // Load a buffer of transforms
        // tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
        // tf_buffer_->setUsingDedicatedThread(true);
        // // Create a utils object to use the utility functions
        // utils_ptr_ = std::make_shared<Utils>();

        // // timer to publish the transform
        // broadcast_timer_ = this->create_wall_timer(100ms,
        //     std::bind(&BroadcasterDemo::broadcast_timer_cb_, this));

        // // timer to publish the transform
        // static_broadcast_timer_ = this->create_wall_timer(10s, std::bind(&BroadcasterDemo::static_broadcast_timer_cb_, this));
           
        // // added for listener
        //  RCLCPP_INFO(this->get_logger(), "Listener for Transform Started");

        // // load a buffer of transforms
        // tf_buffer_ =
        //     std::make_unique<tf2_ros::Buffer>(this->get_clock());
        // transform_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

        // // timer to listen to the transforms
        // listen_timer_ = this->create_wall_timer(1s, std::bind(&ListenerDemo::listen_timer_cb_, this));
    }

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

    double camera_1_x{};
    double camera_1_y{};

    double camera_2_x{};
    double camera_2_y{};

    double camera_3_x{};
    double camera_3_y{};

    double camera_4_x{};
    double camera_4_y{};

    double camera_5_x{};
    double camera_5_y{};

};
