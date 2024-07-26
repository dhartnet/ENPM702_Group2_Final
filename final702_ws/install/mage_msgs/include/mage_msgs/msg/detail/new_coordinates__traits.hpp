// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mage_msgs:msg/NewCoordinates.idl
// generated code does not contain a copyright notice

#ifndef MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__TRAITS_HPP_
#define MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__TRAITS_HPP_

#include "mage_msgs/msg/detail/new_coordinates__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const mage_msgs::msg::NewCoordinates & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x_coordinate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_coordinate: ";
    value_to_yaml(msg.x_coordinate, out);
    out << "\n";
  }

  // member: y_coordinate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_coordinate: ";
    value_to_yaml(msg.y_coordinate, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const mage_msgs::msg::NewCoordinates & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<mage_msgs::msg::NewCoordinates>()
{
  return "mage_msgs::msg::NewCoordinates";
}

template<>
inline const char * name<mage_msgs::msg::NewCoordinates>()
{
  return "mage_msgs/msg/NewCoordinates";
}

template<>
struct has_fixed_size<mage_msgs::msg::NewCoordinates>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mage_msgs::msg::NewCoordinates>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mage_msgs::msg::NewCoordinates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__TRAITS_HPP_
