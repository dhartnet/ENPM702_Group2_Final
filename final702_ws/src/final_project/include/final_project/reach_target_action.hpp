#pragma once

#include "mage_msgs/msg/robot_target.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "mage_msgs/action/robot_target.hpp"
#include "mage_msgs/msg/advanced_logical_camera_image.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include <iostream>
#include <map>
#include <utils.hpp>

// // for static broadcaster
#include "tf2_ros/static_transform_broadcaster.h"
// for dynamic broadcaster
#include "tf2_ros/transform_broadcaster.h"

// needed for the listener
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>

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

        RCLCPP_INFO(this->get_logger(), "Listener demo started");

        // load a buffer of transforms
        tf_buffer_ =
            std::make_unique<tf2_ros::Buffer>(this->get_clock());
        transform_listener_ =
            std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

        // timer to listen to the transforms
        listen_timer_ = this->create_wall_timer(1s, std::bind(&RobotTargetClient::listen_timer_cb_, this));

        // parameter to decide whether to execute the broadcaster or not
        RCLCPP_INFO(this->get_logger(), "Broadcaster demo started");

        // initialize a static transform broadcaster
        tf_static_broadcaster_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);

        // initialize the transform broadcaster
        tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);

        // Load a buffer of transforms
        tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
        tf_buffer_->setUsingDedicatedThread(true);
        // Create a utils object to use the utility functions
        utils_ptr_ = std::make_shared<Utils>();

        // timer to publish the transform
        broadcast_timer_ = this->create_wall_timer(
            100ms,
            std::bind(&RobotTargetClient::broadcast_timer_cb_, this));

        // timer to publish the transform
        static_broadcast_timer_ = this->create_wall_timer(
            10s,
            std::bind(&RobotTargetClient::static_broadcast_timer_cb_, this));
        
        // Load parameters from the YAML file
        this->declare_parameter<std::string>("waypoint1", "green");
        this->declare_parameter<std::string>("waypoint2", "red");
        this->declare_parameter<std::string>("waypoint3", "orange");
        this->declare_parameter<std::string>("waypoint4", "purple");
        this->declare_parameter<std::string>("waypoint5", "blue");

        waypoint_colors_["waypoint1"] = this->get_parameter("waypoint1").as_string();
        waypoint_colors_["waypoint2"] = this->get_parameter("waypoint2").as_string();
        waypoint_colors_["waypoint3"] = this->get_parameter("waypoint3").as_string();
        waypoint_colors_["waypoint4"] = this->get_parameter("waypoint4").as_string();
        waypoint_colors_["waypoint5"] = this->get_parameter("waypoint5").as_string();


        // Create a mutually exclusive callback group
        group1_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

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
            };

        
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
    //add 
    std::unordered_map<std::string, std::string> waypoint_colors_;
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

    /*!< Boolean variable to store the value of the parameter "listen" */
    bool param_listen_;
    /*!< Buffer that stores several seconds of transforms for easy lookup by the listener. */
    std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
    /*!< Transform listener object */
    std::shared_ptr<tf2_ros::TransformListener> transform_listener_{nullptr};
    /*!< Wall timer object */
    rclcpp::TimerBase::SharedPtr listen_timer_;

    /**
     * @brief Listen to a transform
     *
     * @param source_frame Source frame (child frame) of the transform
     * @param target_frame Target frame (parent frame) of the transform
     */
    void listen_transform(const std::string &source_frame, const std::string &target_frame);

    /**
     * @brief Timer to listen to the transform
     *
     */
    void listen_timer_cb_();

    /*!< Boolean parameter to whether or not start the broadcaster */
    bool param_broadcast_;
    /*!< Static broadcaster object */
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> tf_static_broadcaster_;
    /*!< Broadcaster object */
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    /*!< Utils object to access utility functions*/
    std::shared_ptr<Utils> utils_ptr_;
    /*!< Wall timer object for the broadcaster*/
    rclcpp::TimerBase::SharedPtr broadcast_timer_;
    /*!< Wall timer object for the static broadcaster*/
    rclcpp::TimerBase::SharedPtr static_broadcast_timer_;


    /**
     * @brief Timer to broadcast the transform
     *
     */
    void broadcast_timer_cb_();
    /**
     * @brief Timer to broadcast the transform
     *
     */
    void static_broadcast_timer_cb_();

};