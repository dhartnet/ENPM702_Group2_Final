// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mage_msgs:msg/NewCoordinates.idl
// generated code does not contain a copyright notice

#ifndef MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__BUILDER_HPP_
#define MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__BUILDER_HPP_

#include "mage_msgs/msg/detail/new_coordinates__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace mage_msgs
{

namespace msg
{

namespace builder
{

class Init_NewCoordinates_y_coordinate
{
public:
  explicit Init_NewCoordinates_y_coordinate(::mage_msgs::msg::NewCoordinates & msg)
  : msg_(msg)
  {}
  ::mage_msgs::msg::NewCoordinates y_coordinate(::mage_msgs::msg::NewCoordinates::_y_coordinate_type arg)
  {
    msg_.y_coordinate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mage_msgs::msg::NewCoordinates msg_;
};

class Init_NewCoordinates_x_coordinate
{
public:
  Init_NewCoordinates_x_coordinate()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NewCoordinates_y_coordinate x_coordinate(::mage_msgs::msg::NewCoordinates::_x_coordinate_type arg)
  {
    msg_.x_coordinate = std::move(arg);
    return Init_NewCoordinates_y_coordinate(msg_);
  }

private:
  ::mage_msgs::msg::NewCoordinates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mage_msgs::msg::NewCoordinates>()
{
  return mage_msgs::msg::builder::Init_NewCoordinates_x_coordinate();
}

}  // namespace mage_msgs

#endif  // MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__BUILDER_HPP_
