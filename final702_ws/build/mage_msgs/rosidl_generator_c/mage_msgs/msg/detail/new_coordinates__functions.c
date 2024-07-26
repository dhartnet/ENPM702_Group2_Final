// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mage_msgs:msg/NewCoordinates.idl
// generated code does not contain a copyright notice
#include "mage_msgs/msg/detail/new_coordinates__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
mage_msgs__msg__NewCoordinates__init(mage_msgs__msg__NewCoordinates * msg)
{
  if (!msg) {
    return false;
  }
  // x_coordinate
  // y_coordinate
  return true;
}

void
mage_msgs__msg__NewCoordinates__fini(mage_msgs__msg__NewCoordinates * msg)
{
  if (!msg) {
    return;
  }
  // x_coordinate
  // y_coordinate
}

bool
mage_msgs__msg__NewCoordinates__are_equal(const mage_msgs__msg__NewCoordinates * lhs, const mage_msgs__msg__NewCoordinates * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x_coordinate
  if (lhs->x_coordinate != rhs->x_coordinate) {
    return false;
  }
  // y_coordinate
  if (lhs->y_coordinate != rhs->y_coordinate) {
    return false;
  }
  return true;
}

bool
mage_msgs__msg__NewCoordinates__copy(
  const mage_msgs__msg__NewCoordinates * input,
  mage_msgs__msg__NewCoordinates * output)
{
  if (!input || !output) {
    return false;
  }
  // x_coordinate
  output->x_coordinate = input->x_coordinate;
  // y_coordinate
  output->y_coordinate = input->y_coordinate;
  return true;
}

mage_msgs__msg__NewCoordinates *
mage_msgs__msg__NewCoordinates__create()
{
  mage_msgs__msg__NewCoordinates * msg = (mage_msgs__msg__NewCoordinates *)malloc(sizeof(mage_msgs__msg__NewCoordinates));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mage_msgs__msg__NewCoordinates));
  bool success = mage_msgs__msg__NewCoordinates__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
mage_msgs__msg__NewCoordinates__destroy(mage_msgs__msg__NewCoordinates * msg)
{
  if (msg) {
    mage_msgs__msg__NewCoordinates__fini(msg);
  }
  free(msg);
}


bool
mage_msgs__msg__NewCoordinates__Sequence__init(mage_msgs__msg__NewCoordinates__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  mage_msgs__msg__NewCoordinates * data = NULL;
  if (size) {
    data = (mage_msgs__msg__NewCoordinates *)calloc(size, sizeof(mage_msgs__msg__NewCoordinates));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mage_msgs__msg__NewCoordinates__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mage_msgs__msg__NewCoordinates__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mage_msgs__msg__NewCoordinates__Sequence__fini(mage_msgs__msg__NewCoordinates__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mage_msgs__msg__NewCoordinates__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mage_msgs__msg__NewCoordinates__Sequence *
mage_msgs__msg__NewCoordinates__Sequence__create(size_t size)
{
  mage_msgs__msg__NewCoordinates__Sequence * array = (mage_msgs__msg__NewCoordinates__Sequence *)malloc(sizeof(mage_msgs__msg__NewCoordinates__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = mage_msgs__msg__NewCoordinates__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
mage_msgs__msg__NewCoordinates__Sequence__destroy(mage_msgs__msg__NewCoordinates__Sequence * array)
{
  if (array) {
    mage_msgs__msg__NewCoordinates__Sequence__fini(array);
  }
  free(array);
}

bool
mage_msgs__msg__NewCoordinates__Sequence__are_equal(const mage_msgs__msg__NewCoordinates__Sequence * lhs, const mage_msgs__msg__NewCoordinates__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mage_msgs__msg__NewCoordinates__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mage_msgs__msg__NewCoordinates__Sequence__copy(
  const mage_msgs__msg__NewCoordinates__Sequence * input,
  mage_msgs__msg__NewCoordinates__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mage_msgs__msg__NewCoordinates);
    mage_msgs__msg__NewCoordinates * data =
      (mage_msgs__msg__NewCoordinates *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mage_msgs__msg__NewCoordinates__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          mage_msgs__msg__NewCoordinates__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mage_msgs__msg__NewCoordinates__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
