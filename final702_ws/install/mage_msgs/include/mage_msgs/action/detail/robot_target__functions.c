// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mage_msgs:action/RobotTarget.idl
// generated code does not contain a copyright notice
#include "mage_msgs/action/detail/robot_target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `target`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
mage_msgs__action__RobotTarget_Goal__init(mage_msgs__action__RobotTarget_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // target
  if (!geometry_msgs__msg__Point__init(&msg->target)) {
    mage_msgs__action__RobotTarget_Goal__fini(msg);
    return false;
  }
  return true;
}

void
mage_msgs__action__RobotTarget_Goal__fini(mage_msgs__action__RobotTarget_Goal * msg)
{
  if (!msg) {
    return;
  }
  // target
  geometry_msgs__msg__Point__fini(&msg->target);
}

bool
mage_msgs__action__RobotTarget_Goal__are_equal(const mage_msgs__action__RobotTarget_Goal * lhs, const mage_msgs__action__RobotTarget_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->target), &(rhs->target)))
  {
    return false;
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_Goal__copy(
  const mage_msgs__action__RobotTarget_Goal * input,
  mage_msgs__action__RobotTarget_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // target
  if (!geometry_msgs__msg__Point__copy(
      &(input->target), &(output->target)))
  {
    return false;
  }
  return true;
}

mage_msgs__action__RobotTarget_Goal *
mage_msgs__action__RobotTarget_Goal__create()
{
  mage_msgs__action__RobotTarget_Goal * msg = (mage_msgs__action__RobotTarget_Goal *)malloc(sizeof(mage_msgs__action__RobotTarget_Goal));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mage_msgs__action__RobotTarget_Goal));
  bool success = mage_msgs__action__RobotTarget_Goal__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
mage_msgs__action__RobotTarget_Goal__destroy(mage_msgs__action__RobotTarget_Goal * msg)
{
  if (msg) {
    mage_msgs__action__RobotTarget_Goal__fini(msg);
  }
  free(msg);
}


bool
mage_msgs__action__RobotTarget_Goal__Sequence__init(mage_msgs__action__RobotTarget_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  mage_msgs__action__RobotTarget_Goal * data = NULL;
  if (size) {
    data = (mage_msgs__action__RobotTarget_Goal *)calloc(size, sizeof(mage_msgs__action__RobotTarget_Goal));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mage_msgs__action__RobotTarget_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mage_msgs__action__RobotTarget_Goal__fini(&data[i - 1]);
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
mage_msgs__action__RobotTarget_Goal__Sequence__fini(mage_msgs__action__RobotTarget_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mage_msgs__action__RobotTarget_Goal__fini(&array->data[i]);
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

mage_msgs__action__RobotTarget_Goal__Sequence *
mage_msgs__action__RobotTarget_Goal__Sequence__create(size_t size)
{
  mage_msgs__action__RobotTarget_Goal__Sequence * array = (mage_msgs__action__RobotTarget_Goal__Sequence *)malloc(sizeof(mage_msgs__action__RobotTarget_Goal__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = mage_msgs__action__RobotTarget_Goal__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
mage_msgs__action__RobotTarget_Goal__Sequence__destroy(mage_msgs__action__RobotTarget_Goal__Sequence * array)
{
  if (array) {
    mage_msgs__action__RobotTarget_Goal__Sequence__fini(array);
  }
  free(array);
}

bool
mage_msgs__action__RobotTarget_Goal__Sequence__are_equal(const mage_msgs__action__RobotTarget_Goal__Sequence * lhs, const mage_msgs__action__RobotTarget_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mage_msgs__action__RobotTarget_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_Goal__Sequence__copy(
  const mage_msgs__action__RobotTarget_Goal__Sequence * input,
  mage_msgs__action__RobotTarget_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mage_msgs__action__RobotTarget_Goal);
    mage_msgs__action__RobotTarget_Goal * data =
      (mage_msgs__action__RobotTarget_Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mage_msgs__action__RobotTarget_Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          mage_msgs__action__RobotTarget_Goal__fini(&data[i]);
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
    if (!mage_msgs__action__RobotTarget_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
mage_msgs__action__RobotTarget_Result__init(mage_msgs__action__RobotTarget_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    mage_msgs__action__RobotTarget_Result__fini(msg);
    return false;
  }
  return true;
}

void
mage_msgs__action__RobotTarget_Result__fini(mage_msgs__action__RobotTarget_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
mage_msgs__action__RobotTarget_Result__are_equal(const mage_msgs__action__RobotTarget_Result * lhs, const mage_msgs__action__RobotTarget_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_Result__copy(
  const mage_msgs__action__RobotTarget_Result * input,
  mage_msgs__action__RobotTarget_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

mage_msgs__action__RobotTarget_Result *
mage_msgs__action__RobotTarget_Result__create()
{
  mage_msgs__action__RobotTarget_Result * msg = (mage_msgs__action__RobotTarget_Result *)malloc(sizeof(mage_msgs__action__RobotTarget_Result));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mage_msgs__action__RobotTarget_Result));
  bool success = mage_msgs__action__RobotTarget_Result__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
mage_msgs__action__RobotTarget_Result__destroy(mage_msgs__action__RobotTarget_Result * msg)
{
  if (msg) {
    mage_msgs__action__RobotTarget_Result__fini(msg);
  }
  free(msg);
}


bool
mage_msgs__action__RobotTarget_Result__Sequence__init(mage_msgs__action__RobotTarget_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  mage_msgs__action__RobotTarget_Result * data = NULL;
  if (size) {
    data = (mage_msgs__action__RobotTarget_Result *)calloc(size, sizeof(mage_msgs__action__RobotTarget_Result));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mage_msgs__action__RobotTarget_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mage_msgs__action__RobotTarget_Result__fini(&data[i - 1]);
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
mage_msgs__action__RobotTarget_Result__Sequence__fini(mage_msgs__action__RobotTarget_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mage_msgs__action__RobotTarget_Result__fini(&array->data[i]);
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

mage_msgs__action__RobotTarget_Result__Sequence *
mage_msgs__action__RobotTarget_Result__Sequence__create(size_t size)
{
  mage_msgs__action__RobotTarget_Result__Sequence * array = (mage_msgs__action__RobotTarget_Result__Sequence *)malloc(sizeof(mage_msgs__action__RobotTarget_Result__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = mage_msgs__action__RobotTarget_Result__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
mage_msgs__action__RobotTarget_Result__Sequence__destroy(mage_msgs__action__RobotTarget_Result__Sequence * array)
{
  if (array) {
    mage_msgs__action__RobotTarget_Result__Sequence__fini(array);
  }
  free(array);
}

bool
mage_msgs__action__RobotTarget_Result__Sequence__are_equal(const mage_msgs__action__RobotTarget_Result__Sequence * lhs, const mage_msgs__action__RobotTarget_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mage_msgs__action__RobotTarget_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_Result__Sequence__copy(
  const mage_msgs__action__RobotTarget_Result__Sequence * input,
  mage_msgs__action__RobotTarget_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mage_msgs__action__RobotTarget_Result);
    mage_msgs__action__RobotTarget_Result * data =
      (mage_msgs__action__RobotTarget_Result *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mage_msgs__action__RobotTarget_Result__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          mage_msgs__action__RobotTarget_Result__fini(&data[i]);
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
    if (!mage_msgs__action__RobotTarget_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
mage_msgs__action__RobotTarget_Feedback__init(mage_msgs__action__RobotTarget_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // distance_to_goal
  return true;
}

void
mage_msgs__action__RobotTarget_Feedback__fini(mage_msgs__action__RobotTarget_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // distance_to_goal
}

bool
mage_msgs__action__RobotTarget_Feedback__are_equal(const mage_msgs__action__RobotTarget_Feedback * lhs, const mage_msgs__action__RobotTarget_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // distance_to_goal
  if (lhs->distance_to_goal != rhs->distance_to_goal) {
    return false;
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_Feedback__copy(
  const mage_msgs__action__RobotTarget_Feedback * input,
  mage_msgs__action__RobotTarget_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // distance_to_goal
  output->distance_to_goal = input->distance_to_goal;
  return true;
}

mage_msgs__action__RobotTarget_Feedback *
mage_msgs__action__RobotTarget_Feedback__create()
{
  mage_msgs__action__RobotTarget_Feedback * msg = (mage_msgs__action__RobotTarget_Feedback *)malloc(sizeof(mage_msgs__action__RobotTarget_Feedback));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mage_msgs__action__RobotTarget_Feedback));
  bool success = mage_msgs__action__RobotTarget_Feedback__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
mage_msgs__action__RobotTarget_Feedback__destroy(mage_msgs__action__RobotTarget_Feedback * msg)
{
  if (msg) {
    mage_msgs__action__RobotTarget_Feedback__fini(msg);
  }
  free(msg);
}


bool
mage_msgs__action__RobotTarget_Feedback__Sequence__init(mage_msgs__action__RobotTarget_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  mage_msgs__action__RobotTarget_Feedback * data = NULL;
  if (size) {
    data = (mage_msgs__action__RobotTarget_Feedback *)calloc(size, sizeof(mage_msgs__action__RobotTarget_Feedback));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mage_msgs__action__RobotTarget_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mage_msgs__action__RobotTarget_Feedback__fini(&data[i - 1]);
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
mage_msgs__action__RobotTarget_Feedback__Sequence__fini(mage_msgs__action__RobotTarget_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mage_msgs__action__RobotTarget_Feedback__fini(&array->data[i]);
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

mage_msgs__action__RobotTarget_Feedback__Sequence *
mage_msgs__action__RobotTarget_Feedback__Sequence__create(size_t size)
{
  mage_msgs__action__RobotTarget_Feedback__Sequence * array = (mage_msgs__action__RobotTarget_Feedback__Sequence *)malloc(sizeof(mage_msgs__action__RobotTarget_Feedback__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = mage_msgs__action__RobotTarget_Feedback__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
mage_msgs__action__RobotTarget_Feedback__Sequence__destroy(mage_msgs__action__RobotTarget_Feedback__Sequence * array)
{
  if (array) {
    mage_msgs__action__RobotTarget_Feedback__Sequence__fini(array);
  }
  free(array);
}

bool
mage_msgs__action__RobotTarget_Feedback__Sequence__are_equal(const mage_msgs__action__RobotTarget_Feedback__Sequence * lhs, const mage_msgs__action__RobotTarget_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mage_msgs__action__RobotTarget_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_Feedback__Sequence__copy(
  const mage_msgs__action__RobotTarget_Feedback__Sequence * input,
  mage_msgs__action__RobotTarget_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mage_msgs__action__RobotTarget_Feedback);
    mage_msgs__action__RobotTarget_Feedback * data =
      (mage_msgs__action__RobotTarget_Feedback *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mage_msgs__action__RobotTarget_Feedback__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          mage_msgs__action__RobotTarget_Feedback__fini(&data[i]);
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
    if (!mage_msgs__action__RobotTarget_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "mage_msgs/action/detail/robot_target__functions.h"

bool
mage_msgs__action__RobotTarget_SendGoal_Request__init(mage_msgs__action__RobotTarget_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mage_msgs__action__RobotTarget_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!mage_msgs__action__RobotTarget_Goal__init(&msg->goal)) {
    mage_msgs__action__RobotTarget_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
mage_msgs__action__RobotTarget_SendGoal_Request__fini(mage_msgs__action__RobotTarget_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  mage_msgs__action__RobotTarget_Goal__fini(&msg->goal);
}

bool
mage_msgs__action__RobotTarget_SendGoal_Request__are_equal(const mage_msgs__action__RobotTarget_SendGoal_Request * lhs, const mage_msgs__action__RobotTarget_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!mage_msgs__action__RobotTarget_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_SendGoal_Request__copy(
  const mage_msgs__action__RobotTarget_SendGoal_Request * input,
  mage_msgs__action__RobotTarget_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!mage_msgs__action__RobotTarget_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

mage_msgs__action__RobotTarget_SendGoal_Request *
mage_msgs__action__RobotTarget_SendGoal_Request__create()
{
  mage_msgs__action__RobotTarget_SendGoal_Request * msg = (mage_msgs__action__RobotTarget_SendGoal_Request *)malloc(sizeof(mage_msgs__action__RobotTarget_SendGoal_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mage_msgs__action__RobotTarget_SendGoal_Request));
  bool success = mage_msgs__action__RobotTarget_SendGoal_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
mage_msgs__action__RobotTarget_SendGoal_Request__destroy(mage_msgs__action__RobotTarget_SendGoal_Request * msg)
{
  if (msg) {
    mage_msgs__action__RobotTarget_SendGoal_Request__fini(msg);
  }
  free(msg);
}


bool
mage_msgs__action__RobotTarget_SendGoal_Request__Sequence__init(mage_msgs__action__RobotTarget_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  mage_msgs__action__RobotTarget_SendGoal_Request * data = NULL;
  if (size) {
    data = (mage_msgs__action__RobotTarget_SendGoal_Request *)calloc(size, sizeof(mage_msgs__action__RobotTarget_SendGoal_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mage_msgs__action__RobotTarget_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mage_msgs__action__RobotTarget_SendGoal_Request__fini(&data[i - 1]);
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
mage_msgs__action__RobotTarget_SendGoal_Request__Sequence__fini(mage_msgs__action__RobotTarget_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mage_msgs__action__RobotTarget_SendGoal_Request__fini(&array->data[i]);
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

mage_msgs__action__RobotTarget_SendGoal_Request__Sequence *
mage_msgs__action__RobotTarget_SendGoal_Request__Sequence__create(size_t size)
{
  mage_msgs__action__RobotTarget_SendGoal_Request__Sequence * array = (mage_msgs__action__RobotTarget_SendGoal_Request__Sequence *)malloc(sizeof(mage_msgs__action__RobotTarget_SendGoal_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = mage_msgs__action__RobotTarget_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
mage_msgs__action__RobotTarget_SendGoal_Request__Sequence__destroy(mage_msgs__action__RobotTarget_SendGoal_Request__Sequence * array)
{
  if (array) {
    mage_msgs__action__RobotTarget_SendGoal_Request__Sequence__fini(array);
  }
  free(array);
}

bool
mage_msgs__action__RobotTarget_SendGoal_Request__Sequence__are_equal(const mage_msgs__action__RobotTarget_SendGoal_Request__Sequence * lhs, const mage_msgs__action__RobotTarget_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mage_msgs__action__RobotTarget_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_SendGoal_Request__Sequence__copy(
  const mage_msgs__action__RobotTarget_SendGoal_Request__Sequence * input,
  mage_msgs__action__RobotTarget_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mage_msgs__action__RobotTarget_SendGoal_Request);
    mage_msgs__action__RobotTarget_SendGoal_Request * data =
      (mage_msgs__action__RobotTarget_SendGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mage_msgs__action__RobotTarget_SendGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          mage_msgs__action__RobotTarget_SendGoal_Request__fini(&data[i]);
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
    if (!mage_msgs__action__RobotTarget_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
mage_msgs__action__RobotTarget_SendGoal_Response__init(mage_msgs__action__RobotTarget_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    mage_msgs__action__RobotTarget_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
mage_msgs__action__RobotTarget_SendGoal_Response__fini(mage_msgs__action__RobotTarget_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
mage_msgs__action__RobotTarget_SendGoal_Response__are_equal(const mage_msgs__action__RobotTarget_SendGoal_Response * lhs, const mage_msgs__action__RobotTarget_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_SendGoal_Response__copy(
  const mage_msgs__action__RobotTarget_SendGoal_Response * input,
  mage_msgs__action__RobotTarget_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

mage_msgs__action__RobotTarget_SendGoal_Response *
mage_msgs__action__RobotTarget_SendGoal_Response__create()
{
  mage_msgs__action__RobotTarget_SendGoal_Response * msg = (mage_msgs__action__RobotTarget_SendGoal_Response *)malloc(sizeof(mage_msgs__action__RobotTarget_SendGoal_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mage_msgs__action__RobotTarget_SendGoal_Response));
  bool success = mage_msgs__action__RobotTarget_SendGoal_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
mage_msgs__action__RobotTarget_SendGoal_Response__destroy(mage_msgs__action__RobotTarget_SendGoal_Response * msg)
{
  if (msg) {
    mage_msgs__action__RobotTarget_SendGoal_Response__fini(msg);
  }
  free(msg);
}


bool
mage_msgs__action__RobotTarget_SendGoal_Response__Sequence__init(mage_msgs__action__RobotTarget_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  mage_msgs__action__RobotTarget_SendGoal_Response * data = NULL;
  if (size) {
    data = (mage_msgs__action__RobotTarget_SendGoal_Response *)calloc(size, sizeof(mage_msgs__action__RobotTarget_SendGoal_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mage_msgs__action__RobotTarget_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mage_msgs__action__RobotTarget_SendGoal_Response__fini(&data[i - 1]);
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
mage_msgs__action__RobotTarget_SendGoal_Response__Sequence__fini(mage_msgs__action__RobotTarget_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mage_msgs__action__RobotTarget_SendGoal_Response__fini(&array->data[i]);
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

mage_msgs__action__RobotTarget_SendGoal_Response__Sequence *
mage_msgs__action__RobotTarget_SendGoal_Response__Sequence__create(size_t size)
{
  mage_msgs__action__RobotTarget_SendGoal_Response__Sequence * array = (mage_msgs__action__RobotTarget_SendGoal_Response__Sequence *)malloc(sizeof(mage_msgs__action__RobotTarget_SendGoal_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = mage_msgs__action__RobotTarget_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
mage_msgs__action__RobotTarget_SendGoal_Response__Sequence__destroy(mage_msgs__action__RobotTarget_SendGoal_Response__Sequence * array)
{
  if (array) {
    mage_msgs__action__RobotTarget_SendGoal_Response__Sequence__fini(array);
  }
  free(array);
}

bool
mage_msgs__action__RobotTarget_SendGoal_Response__Sequence__are_equal(const mage_msgs__action__RobotTarget_SendGoal_Response__Sequence * lhs, const mage_msgs__action__RobotTarget_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mage_msgs__action__RobotTarget_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_SendGoal_Response__Sequence__copy(
  const mage_msgs__action__RobotTarget_SendGoal_Response__Sequence * input,
  mage_msgs__action__RobotTarget_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mage_msgs__action__RobotTarget_SendGoal_Response);
    mage_msgs__action__RobotTarget_SendGoal_Response * data =
      (mage_msgs__action__RobotTarget_SendGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mage_msgs__action__RobotTarget_SendGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          mage_msgs__action__RobotTarget_SendGoal_Response__fini(&data[i]);
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
    if (!mage_msgs__action__RobotTarget_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
mage_msgs__action__RobotTarget_GetResult_Request__init(mage_msgs__action__RobotTarget_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mage_msgs__action__RobotTarget_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
mage_msgs__action__RobotTarget_GetResult_Request__fini(mage_msgs__action__RobotTarget_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
mage_msgs__action__RobotTarget_GetResult_Request__are_equal(const mage_msgs__action__RobotTarget_GetResult_Request * lhs, const mage_msgs__action__RobotTarget_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_GetResult_Request__copy(
  const mage_msgs__action__RobotTarget_GetResult_Request * input,
  mage_msgs__action__RobotTarget_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

mage_msgs__action__RobotTarget_GetResult_Request *
mage_msgs__action__RobotTarget_GetResult_Request__create()
{
  mage_msgs__action__RobotTarget_GetResult_Request * msg = (mage_msgs__action__RobotTarget_GetResult_Request *)malloc(sizeof(mage_msgs__action__RobotTarget_GetResult_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mage_msgs__action__RobotTarget_GetResult_Request));
  bool success = mage_msgs__action__RobotTarget_GetResult_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
mage_msgs__action__RobotTarget_GetResult_Request__destroy(mage_msgs__action__RobotTarget_GetResult_Request * msg)
{
  if (msg) {
    mage_msgs__action__RobotTarget_GetResult_Request__fini(msg);
  }
  free(msg);
}


bool
mage_msgs__action__RobotTarget_GetResult_Request__Sequence__init(mage_msgs__action__RobotTarget_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  mage_msgs__action__RobotTarget_GetResult_Request * data = NULL;
  if (size) {
    data = (mage_msgs__action__RobotTarget_GetResult_Request *)calloc(size, sizeof(mage_msgs__action__RobotTarget_GetResult_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mage_msgs__action__RobotTarget_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mage_msgs__action__RobotTarget_GetResult_Request__fini(&data[i - 1]);
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
mage_msgs__action__RobotTarget_GetResult_Request__Sequence__fini(mage_msgs__action__RobotTarget_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mage_msgs__action__RobotTarget_GetResult_Request__fini(&array->data[i]);
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

mage_msgs__action__RobotTarget_GetResult_Request__Sequence *
mage_msgs__action__RobotTarget_GetResult_Request__Sequence__create(size_t size)
{
  mage_msgs__action__RobotTarget_GetResult_Request__Sequence * array = (mage_msgs__action__RobotTarget_GetResult_Request__Sequence *)malloc(sizeof(mage_msgs__action__RobotTarget_GetResult_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = mage_msgs__action__RobotTarget_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
mage_msgs__action__RobotTarget_GetResult_Request__Sequence__destroy(mage_msgs__action__RobotTarget_GetResult_Request__Sequence * array)
{
  if (array) {
    mage_msgs__action__RobotTarget_GetResult_Request__Sequence__fini(array);
  }
  free(array);
}

bool
mage_msgs__action__RobotTarget_GetResult_Request__Sequence__are_equal(const mage_msgs__action__RobotTarget_GetResult_Request__Sequence * lhs, const mage_msgs__action__RobotTarget_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mage_msgs__action__RobotTarget_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_GetResult_Request__Sequence__copy(
  const mage_msgs__action__RobotTarget_GetResult_Request__Sequence * input,
  mage_msgs__action__RobotTarget_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mage_msgs__action__RobotTarget_GetResult_Request);
    mage_msgs__action__RobotTarget_GetResult_Request * data =
      (mage_msgs__action__RobotTarget_GetResult_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mage_msgs__action__RobotTarget_GetResult_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          mage_msgs__action__RobotTarget_GetResult_Request__fini(&data[i]);
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
    if (!mage_msgs__action__RobotTarget_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "mage_msgs/action/detail/robot_target__functions.h"

bool
mage_msgs__action__RobotTarget_GetResult_Response__init(mage_msgs__action__RobotTarget_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!mage_msgs__action__RobotTarget_Result__init(&msg->result)) {
    mage_msgs__action__RobotTarget_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
mage_msgs__action__RobotTarget_GetResult_Response__fini(mage_msgs__action__RobotTarget_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  mage_msgs__action__RobotTarget_Result__fini(&msg->result);
}

bool
mage_msgs__action__RobotTarget_GetResult_Response__are_equal(const mage_msgs__action__RobotTarget_GetResult_Response * lhs, const mage_msgs__action__RobotTarget_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!mage_msgs__action__RobotTarget_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_GetResult_Response__copy(
  const mage_msgs__action__RobotTarget_GetResult_Response * input,
  mage_msgs__action__RobotTarget_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!mage_msgs__action__RobotTarget_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

mage_msgs__action__RobotTarget_GetResult_Response *
mage_msgs__action__RobotTarget_GetResult_Response__create()
{
  mage_msgs__action__RobotTarget_GetResult_Response * msg = (mage_msgs__action__RobotTarget_GetResult_Response *)malloc(sizeof(mage_msgs__action__RobotTarget_GetResult_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mage_msgs__action__RobotTarget_GetResult_Response));
  bool success = mage_msgs__action__RobotTarget_GetResult_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
mage_msgs__action__RobotTarget_GetResult_Response__destroy(mage_msgs__action__RobotTarget_GetResult_Response * msg)
{
  if (msg) {
    mage_msgs__action__RobotTarget_GetResult_Response__fini(msg);
  }
  free(msg);
}


bool
mage_msgs__action__RobotTarget_GetResult_Response__Sequence__init(mage_msgs__action__RobotTarget_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  mage_msgs__action__RobotTarget_GetResult_Response * data = NULL;
  if (size) {
    data = (mage_msgs__action__RobotTarget_GetResult_Response *)calloc(size, sizeof(mage_msgs__action__RobotTarget_GetResult_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mage_msgs__action__RobotTarget_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mage_msgs__action__RobotTarget_GetResult_Response__fini(&data[i - 1]);
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
mage_msgs__action__RobotTarget_GetResult_Response__Sequence__fini(mage_msgs__action__RobotTarget_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mage_msgs__action__RobotTarget_GetResult_Response__fini(&array->data[i]);
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

mage_msgs__action__RobotTarget_GetResult_Response__Sequence *
mage_msgs__action__RobotTarget_GetResult_Response__Sequence__create(size_t size)
{
  mage_msgs__action__RobotTarget_GetResult_Response__Sequence * array = (mage_msgs__action__RobotTarget_GetResult_Response__Sequence *)malloc(sizeof(mage_msgs__action__RobotTarget_GetResult_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = mage_msgs__action__RobotTarget_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
mage_msgs__action__RobotTarget_GetResult_Response__Sequence__destroy(mage_msgs__action__RobotTarget_GetResult_Response__Sequence * array)
{
  if (array) {
    mage_msgs__action__RobotTarget_GetResult_Response__Sequence__fini(array);
  }
  free(array);
}

bool
mage_msgs__action__RobotTarget_GetResult_Response__Sequence__are_equal(const mage_msgs__action__RobotTarget_GetResult_Response__Sequence * lhs, const mage_msgs__action__RobotTarget_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mage_msgs__action__RobotTarget_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_GetResult_Response__Sequence__copy(
  const mage_msgs__action__RobotTarget_GetResult_Response__Sequence * input,
  mage_msgs__action__RobotTarget_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mage_msgs__action__RobotTarget_GetResult_Response);
    mage_msgs__action__RobotTarget_GetResult_Response * data =
      (mage_msgs__action__RobotTarget_GetResult_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mage_msgs__action__RobotTarget_GetResult_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          mage_msgs__action__RobotTarget_GetResult_Response__fini(&data[i]);
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
    if (!mage_msgs__action__RobotTarget_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "mage_msgs/action/detail/robot_target__functions.h"

bool
mage_msgs__action__RobotTarget_FeedbackMessage__init(mage_msgs__action__RobotTarget_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mage_msgs__action__RobotTarget_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!mage_msgs__action__RobotTarget_Feedback__init(&msg->feedback)) {
    mage_msgs__action__RobotTarget_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
mage_msgs__action__RobotTarget_FeedbackMessage__fini(mage_msgs__action__RobotTarget_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  mage_msgs__action__RobotTarget_Feedback__fini(&msg->feedback);
}

bool
mage_msgs__action__RobotTarget_FeedbackMessage__are_equal(const mage_msgs__action__RobotTarget_FeedbackMessage * lhs, const mage_msgs__action__RobotTarget_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!mage_msgs__action__RobotTarget_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_FeedbackMessage__copy(
  const mage_msgs__action__RobotTarget_FeedbackMessage * input,
  mage_msgs__action__RobotTarget_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!mage_msgs__action__RobotTarget_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

mage_msgs__action__RobotTarget_FeedbackMessage *
mage_msgs__action__RobotTarget_FeedbackMessage__create()
{
  mage_msgs__action__RobotTarget_FeedbackMessage * msg = (mage_msgs__action__RobotTarget_FeedbackMessage *)malloc(sizeof(mage_msgs__action__RobotTarget_FeedbackMessage));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mage_msgs__action__RobotTarget_FeedbackMessage));
  bool success = mage_msgs__action__RobotTarget_FeedbackMessage__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
mage_msgs__action__RobotTarget_FeedbackMessage__destroy(mage_msgs__action__RobotTarget_FeedbackMessage * msg)
{
  if (msg) {
    mage_msgs__action__RobotTarget_FeedbackMessage__fini(msg);
  }
  free(msg);
}


bool
mage_msgs__action__RobotTarget_FeedbackMessage__Sequence__init(mage_msgs__action__RobotTarget_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  mage_msgs__action__RobotTarget_FeedbackMessage * data = NULL;
  if (size) {
    data = (mage_msgs__action__RobotTarget_FeedbackMessage *)calloc(size, sizeof(mage_msgs__action__RobotTarget_FeedbackMessage));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mage_msgs__action__RobotTarget_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mage_msgs__action__RobotTarget_FeedbackMessage__fini(&data[i - 1]);
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
mage_msgs__action__RobotTarget_FeedbackMessage__Sequence__fini(mage_msgs__action__RobotTarget_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mage_msgs__action__RobotTarget_FeedbackMessage__fini(&array->data[i]);
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

mage_msgs__action__RobotTarget_FeedbackMessage__Sequence *
mage_msgs__action__RobotTarget_FeedbackMessage__Sequence__create(size_t size)
{
  mage_msgs__action__RobotTarget_FeedbackMessage__Sequence * array = (mage_msgs__action__RobotTarget_FeedbackMessage__Sequence *)malloc(sizeof(mage_msgs__action__RobotTarget_FeedbackMessage__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = mage_msgs__action__RobotTarget_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
mage_msgs__action__RobotTarget_FeedbackMessage__Sequence__destroy(mage_msgs__action__RobotTarget_FeedbackMessage__Sequence * array)
{
  if (array) {
    mage_msgs__action__RobotTarget_FeedbackMessage__Sequence__fini(array);
  }
  free(array);
}

bool
mage_msgs__action__RobotTarget_FeedbackMessage__Sequence__are_equal(const mage_msgs__action__RobotTarget_FeedbackMessage__Sequence * lhs, const mage_msgs__action__RobotTarget_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mage_msgs__action__RobotTarget_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mage_msgs__action__RobotTarget_FeedbackMessage__Sequence__copy(
  const mage_msgs__action__RobotTarget_FeedbackMessage__Sequence * input,
  mage_msgs__action__RobotTarget_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mage_msgs__action__RobotTarget_FeedbackMessage);
    mage_msgs__action__RobotTarget_FeedbackMessage * data =
      (mage_msgs__action__RobotTarget_FeedbackMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mage_msgs__action__RobotTarget_FeedbackMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          mage_msgs__action__RobotTarget_FeedbackMessage__fini(&data[i]);
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
    if (!mage_msgs__action__RobotTarget_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
