// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from mage_msgs:msg/NewCoordinates.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "mage_msgs/msg/detail/new_coordinates__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace mage_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void NewCoordinates_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) mage_msgs::msg::NewCoordinates(_init);
}

void NewCoordinates_fini_function(void * message_memory)
{
  auto typed_message = static_cast<mage_msgs::msg::NewCoordinates *>(message_memory);
  typed_message->~NewCoordinates();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember NewCoordinates_message_member_array[2] = {
  {
    "x_coordinate",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mage_msgs::msg::NewCoordinates, x_coordinate),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y_coordinate",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mage_msgs::msg::NewCoordinates, y_coordinate),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers NewCoordinates_message_members = {
  "mage_msgs::msg",  // message namespace
  "NewCoordinates",  // message name
  2,  // number of fields
  sizeof(mage_msgs::msg::NewCoordinates),
  NewCoordinates_message_member_array,  // message members
  NewCoordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  NewCoordinates_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t NewCoordinates_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &NewCoordinates_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace mage_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mage_msgs::msg::NewCoordinates>()
{
  return &::mage_msgs::msg::rosidl_typesupport_introspection_cpp::NewCoordinates_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mage_msgs, msg, NewCoordinates)() {
  return &::mage_msgs::msg::rosidl_typesupport_introspection_cpp::NewCoordinates_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
