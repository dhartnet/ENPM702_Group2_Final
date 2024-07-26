// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from mage_msgs:msg/NewCoordinates.idl
// generated code does not contain a copyright notice
#include "mage_msgs/msg/detail/new_coordinates__rosidl_typesupport_fastrtps_cpp.hpp"
#include "mage_msgs/msg/detail/new_coordinates__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace mage_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mage_msgs
cdr_serialize(
  const mage_msgs::msg::NewCoordinates & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: x_coordinate
  cdr << ros_message.x_coordinate;
  // Member: y_coordinate
  cdr << ros_message.y_coordinate;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mage_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  mage_msgs::msg::NewCoordinates & ros_message)
{
  // Member: x_coordinate
  cdr >> ros_message.x_coordinate;

  // Member: y_coordinate
  cdr >> ros_message.y_coordinate;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mage_msgs
get_serialized_size(
  const mage_msgs::msg::NewCoordinates & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: x_coordinate
  {
    size_t item_size = sizeof(ros_message.x_coordinate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: y_coordinate
  {
    size_t item_size = sizeof(ros_message.y_coordinate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mage_msgs
max_serialized_size_NewCoordinates(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: x_coordinate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: y_coordinate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _NewCoordinates__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const mage_msgs::msg::NewCoordinates *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _NewCoordinates__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<mage_msgs::msg::NewCoordinates *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _NewCoordinates__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const mage_msgs::msg::NewCoordinates *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _NewCoordinates__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_NewCoordinates(full_bounded, 0);
}

static message_type_support_callbacks_t _NewCoordinates__callbacks = {
  "mage_msgs::msg",
  "NewCoordinates",
  _NewCoordinates__cdr_serialize,
  _NewCoordinates__cdr_deserialize,
  _NewCoordinates__get_serialized_size,
  _NewCoordinates__max_serialized_size
};

static rosidl_message_type_support_t _NewCoordinates__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_NewCoordinates__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace mage_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_mage_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<mage_msgs::msg::NewCoordinates>()
{
  return &mage_msgs::msg::typesupport_fastrtps_cpp::_NewCoordinates__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mage_msgs, msg, NewCoordinates)() {
  return &mage_msgs::msg::typesupport_fastrtps_cpp::_NewCoordinates__handle;
}

#ifdef __cplusplus
}
#endif
