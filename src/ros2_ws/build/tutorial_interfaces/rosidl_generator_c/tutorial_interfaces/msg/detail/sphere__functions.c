// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tutorial_interfaces:msg/Sphere.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/sphere__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `center`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
tutorial_interfaces__msg__Sphere__init(tutorial_interfaces__msg__Sphere * msg)
{
  if (!msg) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__init(&msg->center)) {
    tutorial_interfaces__msg__Sphere__fini(msg);
    return false;
  }
  // radius
  return true;
}

void
tutorial_interfaces__msg__Sphere__fini(tutorial_interfaces__msg__Sphere * msg)
{
  if (!msg) {
    return;
  }
  // center
  geometry_msgs__msg__Point__fini(&msg->center);
  // radius
}

bool
tutorial_interfaces__msg__Sphere__are_equal(const tutorial_interfaces__msg__Sphere * lhs, const tutorial_interfaces__msg__Sphere * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->center), &(rhs->center)))
  {
    return false;
  }
  // radius
  if (lhs->radius != rhs->radius) {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__msg__Sphere__copy(
  const tutorial_interfaces__msg__Sphere * input,
  tutorial_interfaces__msg__Sphere * output)
{
  if (!input || !output) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__copy(
      &(input->center), &(output->center)))
  {
    return false;
  }
  // radius
  output->radius = input->radius;
  return true;
}

tutorial_interfaces__msg__Sphere *
tutorial_interfaces__msg__Sphere__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__msg__Sphere * msg = (tutorial_interfaces__msg__Sphere *)allocator.allocate(sizeof(tutorial_interfaces__msg__Sphere), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__msg__Sphere));
  bool success = tutorial_interfaces__msg__Sphere__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__msg__Sphere__destroy(tutorial_interfaces__msg__Sphere * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__msg__Sphere__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__msg__Sphere__Sequence__init(tutorial_interfaces__msg__Sphere__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__msg__Sphere * data = NULL;

  if (size) {
    data = (tutorial_interfaces__msg__Sphere *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__msg__Sphere), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__msg__Sphere__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__msg__Sphere__fini(&data[i - 1]);
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
tutorial_interfaces__msg__Sphere__Sequence__fini(tutorial_interfaces__msg__Sphere__Sequence * array)
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
      tutorial_interfaces__msg__Sphere__fini(&array->data[i]);
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

tutorial_interfaces__msg__Sphere__Sequence *
tutorial_interfaces__msg__Sphere__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__msg__Sphere__Sequence * array = (tutorial_interfaces__msg__Sphere__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__msg__Sphere__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__msg__Sphere__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__msg__Sphere__Sequence__destroy(tutorial_interfaces__msg__Sphere__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__msg__Sphere__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__msg__Sphere__Sequence__are_equal(const tutorial_interfaces__msg__Sphere__Sequence * lhs, const tutorial_interfaces__msg__Sphere__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__msg__Sphere__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__msg__Sphere__Sequence__copy(
  const tutorial_interfaces__msg__Sphere__Sequence * input,
  tutorial_interfaces__msg__Sphere__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__msg__Sphere);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__msg__Sphere * data =
      (tutorial_interfaces__msg__Sphere *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__msg__Sphere__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__msg__Sphere__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__msg__Sphere__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
