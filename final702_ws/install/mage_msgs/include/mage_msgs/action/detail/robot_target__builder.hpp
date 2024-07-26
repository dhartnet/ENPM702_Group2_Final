// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mage_msgs:action/RobotTarget.idl
// generated code does not contain a copyright notice

#ifndef MAGE_MSGS__ACTION__DETAIL__ROBOT_TARGET__BUILDER_HPP_
#define MAGE_MSGS__ACTION__DETAIL__ROBOT_TARGET__BUILDER_HPP_

#include "mage_msgs/action/detail/robot_target__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace mage_msgs
{

namespace action
{

namespace builder
{

class Init_RobotTarget_Goal_target
{
public:
  Init_RobotTarget_Goal_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mage_msgs::action::RobotTarget_Goal target(::mage_msgs::action::RobotTarget_Goal::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mage_msgs::action::RobotTarget_Goal>()
{
  return mage_msgs::action::builder::Init_RobotTarget_Goal_target();
}

}  // namespace mage_msgs


namespace mage_msgs
{

namespace action
{

namespace builder
{

class Init_RobotTarget_Result_message
{
public:
  explicit Init_RobotTarget_Result_message(::mage_msgs::action::RobotTarget_Result & msg)
  : msg_(msg)
  {}
  ::mage_msgs::action::RobotTarget_Result message(::mage_msgs::action::RobotTarget_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_Result msg_;
};

class Init_RobotTarget_Result_success
{
public:
  Init_RobotTarget_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTarget_Result_message success(::mage_msgs::action::RobotTarget_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_RobotTarget_Result_message(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mage_msgs::action::RobotTarget_Result>()
{
  return mage_msgs::action::builder::Init_RobotTarget_Result_success();
}

}  // namespace mage_msgs


namespace mage_msgs
{

namespace action
{

namespace builder
{

class Init_RobotTarget_Feedback_distance_to_goal
{
public:
  Init_RobotTarget_Feedback_distance_to_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mage_msgs::action::RobotTarget_Feedback distance_to_goal(::mage_msgs::action::RobotTarget_Feedback::_distance_to_goal_type arg)
  {
    msg_.distance_to_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mage_msgs::action::RobotTarget_Feedback>()
{
  return mage_msgs::action::builder::Init_RobotTarget_Feedback_distance_to_goal();
}

}  // namespace mage_msgs


namespace mage_msgs
{

namespace action
{

namespace builder
{

class Init_RobotTarget_SendGoal_Request_goal
{
public:
  explicit Init_RobotTarget_SendGoal_Request_goal(::mage_msgs::action::RobotTarget_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::mage_msgs::action::RobotTarget_SendGoal_Request goal(::mage_msgs::action::RobotTarget_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_SendGoal_Request msg_;
};

class Init_RobotTarget_SendGoal_Request_goal_id
{
public:
  Init_RobotTarget_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTarget_SendGoal_Request_goal goal_id(::mage_msgs::action::RobotTarget_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RobotTarget_SendGoal_Request_goal(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mage_msgs::action::RobotTarget_SendGoal_Request>()
{
  return mage_msgs::action::builder::Init_RobotTarget_SendGoal_Request_goal_id();
}

}  // namespace mage_msgs


namespace mage_msgs
{

namespace action
{

namespace builder
{

class Init_RobotTarget_SendGoal_Response_stamp
{
public:
  explicit Init_RobotTarget_SendGoal_Response_stamp(::mage_msgs::action::RobotTarget_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::mage_msgs::action::RobotTarget_SendGoal_Response stamp(::mage_msgs::action::RobotTarget_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_SendGoal_Response msg_;
};

class Init_RobotTarget_SendGoal_Response_accepted
{
public:
  Init_RobotTarget_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTarget_SendGoal_Response_stamp accepted(::mage_msgs::action::RobotTarget_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_RobotTarget_SendGoal_Response_stamp(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mage_msgs::action::RobotTarget_SendGoal_Response>()
{
  return mage_msgs::action::builder::Init_RobotTarget_SendGoal_Response_accepted();
}

}  // namespace mage_msgs


namespace mage_msgs
{

namespace action
{

namespace builder
{

class Init_RobotTarget_GetResult_Request_goal_id
{
public:
  Init_RobotTarget_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mage_msgs::action::RobotTarget_GetResult_Request goal_id(::mage_msgs::action::RobotTarget_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mage_msgs::action::RobotTarget_GetResult_Request>()
{
  return mage_msgs::action::builder::Init_RobotTarget_GetResult_Request_goal_id();
}

}  // namespace mage_msgs


namespace mage_msgs
{

namespace action
{

namespace builder
{

class Init_RobotTarget_GetResult_Response_result
{
public:
  explicit Init_RobotTarget_GetResult_Response_result(::mage_msgs::action::RobotTarget_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::mage_msgs::action::RobotTarget_GetResult_Response result(::mage_msgs::action::RobotTarget_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_GetResult_Response msg_;
};

class Init_RobotTarget_GetResult_Response_status
{
public:
  Init_RobotTarget_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTarget_GetResult_Response_result status(::mage_msgs::action::RobotTarget_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_RobotTarget_GetResult_Response_result(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mage_msgs::action::RobotTarget_GetResult_Response>()
{
  return mage_msgs::action::builder::Init_RobotTarget_GetResult_Response_status();
}

}  // namespace mage_msgs


namespace mage_msgs
{

namespace action
{

namespace builder
{

class Init_RobotTarget_FeedbackMessage_feedback
{
public:
  explicit Init_RobotTarget_FeedbackMessage_feedback(::mage_msgs::action::RobotTarget_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::mage_msgs::action::RobotTarget_FeedbackMessage feedback(::mage_msgs::action::RobotTarget_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_FeedbackMessage msg_;
};

class Init_RobotTarget_FeedbackMessage_goal_id
{
public:
  Init_RobotTarget_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTarget_FeedbackMessage_feedback goal_id(::mage_msgs::action::RobotTarget_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RobotTarget_FeedbackMessage_feedback(msg_);
  }

private:
  ::mage_msgs::action::RobotTarget_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mage_msgs::action::RobotTarget_FeedbackMessage>()
{
  return mage_msgs::action::builder::Init_RobotTarget_FeedbackMessage_goal_id();
}

}  // namespace mage_msgs

#endif  // MAGE_MSGS__ACTION__DETAIL__ROBOT_TARGET__BUILDER_HPP_
