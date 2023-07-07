// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_shm_demo:msg/ShmTopic.idl
// generated code does not contain a copyright notice
#include "ros2_shm_demo/msg/detail/shm_topic__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ros2_shm_demo__msg__ShmTopic__init(ros2_shm_demo__msg__ShmTopic * msg)
{
  if (!msg) {
    return false;
  }
  // data
  // size
  // counter
  return true;
}

void
ros2_shm_demo__msg__ShmTopic__fini(ros2_shm_demo__msg__ShmTopic * msg)
{
  if (!msg) {
    return;
  }
  // data
  // size
  // counter
}

bool
ros2_shm_demo__msg__ShmTopic__are_equal(const ros2_shm_demo__msg__ShmTopic * lhs, const ros2_shm_demo__msg__ShmTopic * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  for (size_t i = 0; i < 256; ++i) {
    if (lhs->data[i] != rhs->data[i]) {
      return false;
    }
  }
  // size
  if (lhs->size != rhs->size) {
    return false;
  }
  // counter
  if (lhs->counter != rhs->counter) {
    return false;
  }
  return true;
}

bool
ros2_shm_demo__msg__ShmTopic__copy(
  const ros2_shm_demo__msg__ShmTopic * input,
  ros2_shm_demo__msg__ShmTopic * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  for (size_t i = 0; i < 256; ++i) {
    output->data[i] = input->data[i];
  }
  // size
  output->size = input->size;
  // counter
  output->counter = input->counter;
  return true;
}

ros2_shm_demo__msg__ShmTopic *
ros2_shm_demo__msg__ShmTopic__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_shm_demo__msg__ShmTopic * msg = (ros2_shm_demo__msg__ShmTopic *)allocator.allocate(sizeof(ros2_shm_demo__msg__ShmTopic), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_shm_demo__msg__ShmTopic));
  bool success = ros2_shm_demo__msg__ShmTopic__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_shm_demo__msg__ShmTopic__destroy(ros2_shm_demo__msg__ShmTopic * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_shm_demo__msg__ShmTopic__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_shm_demo__msg__ShmTopic__Sequence__init(ros2_shm_demo__msg__ShmTopic__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_shm_demo__msg__ShmTopic * data = NULL;

  if (size) {
    data = (ros2_shm_demo__msg__ShmTopic *)allocator.zero_allocate(size, sizeof(ros2_shm_demo__msg__ShmTopic), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_shm_demo__msg__ShmTopic__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_shm_demo__msg__ShmTopic__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ros2_shm_demo__msg__ShmTopic__Sequence__fini(ros2_shm_demo__msg__ShmTopic__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2_shm_demo__msg__ShmTopic__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ros2_shm_demo__msg__ShmTopic__Sequence *
ros2_shm_demo__msg__ShmTopic__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_shm_demo__msg__ShmTopic__Sequence * array = (ros2_shm_demo__msg__ShmTopic__Sequence *)allocator.allocate(sizeof(ros2_shm_demo__msg__ShmTopic__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_shm_demo__msg__ShmTopic__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_shm_demo__msg__ShmTopic__Sequence__destroy(ros2_shm_demo__msg__ShmTopic__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_shm_demo__msg__ShmTopic__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_shm_demo__msg__ShmTopic__Sequence__are_equal(const ros2_shm_demo__msg__ShmTopic__Sequence * lhs, const ros2_shm_demo__msg__ShmTopic__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_shm_demo__msg__ShmTopic__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_shm_demo__msg__ShmTopic__Sequence__copy(
  const ros2_shm_demo__msg__ShmTopic__Sequence * input,
  ros2_shm_demo__msg__ShmTopic__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_shm_demo__msg__ShmTopic);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros2_shm_demo__msg__ShmTopic * data =
      (ros2_shm_demo__msg__ShmTopic *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_shm_demo__msg__ShmTopic__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros2_shm_demo__msg__ShmTopic__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_shm_demo__msg__ShmTopic__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
