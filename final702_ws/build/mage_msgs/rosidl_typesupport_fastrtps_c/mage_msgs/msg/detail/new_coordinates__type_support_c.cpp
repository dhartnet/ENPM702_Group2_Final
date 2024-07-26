// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from mage_msgs:msg/NewCoordinates.idl
// generated code does not contain a copyright notice
#include "mage_msgs/msg/detail/new_coordinates__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "mage_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "mage_msgs/msg/detail/new_coordinates__struct.h"
#include "mage_msgs/msg/detail/new_coordinates__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _NewCoordinates__ros_msg_type = mage_msgs__msg__NewCoordinates;

static bool _NewCoordinates__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _NewCoordinates__ros_msg_type * ros_message = static_cast<const _NewCoordinates__ros_msg_type *>(untyped_ros_message);
  // Field name: x_coordinate
  {
    cdr << ros_message->x_coordinate;
  }

  // Field name: y_coordinate
  {
    cdr << ros_message->y_coordinate;
  }

  return true;
}

static bool _NewCoordinates__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _NewCoordinates__ros_msg_type * ros_message = static_cast<_NewCoordinates__ros_msg_type *>(untyped_ros_message);
  // Field name: x_coordinate
  {
    cdr >> ros_message->x_coordinate;
  }

  // Field name: y_coordinate
  {
    cdr >> ros_message->y_coordinate;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mage_msgs
size_t get_serialized_size_mage_msgs__msg__NewCoordinates(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NewCoordinates__ros_msg_type * ros_message = static_cast<const _NewCoordinates__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name x_coordinate
  {
    size_t item_size = sizeof(ros_message->x_coordinate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y_coordinate
  {
    size_t item_size = sizeof(ros_message->y_coordinate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _NewCoordinates__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_mage_msgs__msg__NewCoordinates(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mage_msgs
size_t max_serialized_size_mage_msgs__msg__NewCoordinates(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: x_coordinate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: y_coordinate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _NewCoordinates__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_mage_msgs__msg__NewCoordinates(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_NewCoordinates = {
  "mage_msgs::msg",
  "NewCoordinates",
  _NewCoordinates__cdr_serialize,
  _NewCoordinates__cdr_deserialize,
  _NewCoordinates__get_serialized_size,
  _NewCoordinates__max_serialized_size
};

static rosidl_message_type_support_t _NewCoordinates__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NewCoordinates,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mage_msgs, msg, NewCoordinates)() {
  return &_NewCoordinates__type_support;
}

#if defined(__cplusplus)
}
#endif
