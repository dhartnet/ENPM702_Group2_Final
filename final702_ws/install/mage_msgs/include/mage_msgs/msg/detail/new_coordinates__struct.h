// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mage_msgs:msg/NewCoordinates.idl
// generated code does not contain a copyright notice

#ifndef MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__STRUCT_H_
#define MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/NewCoordinates in the package mage_msgs.
typedef struct mage_msgs__msg__NewCoordinates
{
  double x_coordinate;
  double y_coordinate;
} mage_msgs__msg__NewCoordinates;

// Struct for a sequence of mage_msgs__msg__NewCoordinates.
typedef struct mage_msgs__msg__NewCoordinates__Sequence
{
  mage_msgs__msg__NewCoordinates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mage_msgs__msg__NewCoordinates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__STRUCT_H_
