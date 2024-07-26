// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mage_msgs:msg/Marker.idl
// generated code does not contain a copyright notice

#ifndef MAGE_MSGS__MSG__DETAIL__MARKER__STRUCT_H_
#define MAGE_MSGS__MSG__DETAIL__MARKER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_with_covariance__struct.h"

// Struct defined in msg/Marker in the package mage_msgs.
typedef struct mage_msgs__msg__Marker
{
  std_msgs__msg__Header header;
  uint32_t id;
  geometry_msgs__msg__PoseWithCovariance pose;
  double confidence;
} mage_msgs__msg__Marker;

// Struct for a sequence of mage_msgs__msg__Marker.
typedef struct mage_msgs__msg__Marker__Sequence
{
  mage_msgs__msg__Marker * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mage_msgs__msg__Marker__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAGE_MSGS__MSG__DETAIL__MARKER__STRUCT_H_
