// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_shm_demo:msg/ShmTopic.idl
// generated code does not contain a copyright notice

#ifndef ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__STRUCT_H_
#define ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MAX_SIZE'.
enum
{
  ros2_shm_demo__msg__ShmTopic__MAX_SIZE = 255
};

/// Struct defined in msg/ShmTopic in the package ros2_shm_demo.
/**
  * For Shared Memory demonstration
  *
  * Note that we cannot use unbounded strings like 
  * string data
  * for shared memory transfer
  *
  * string data
  * is possible but the generated type is more cumbersome to use
  *
  * A generic char array allows passing arbitrary data.
 */
typedef struct ros2_shm_demo__msg__ShmTopic
{
  uint8_t data[256];
  uint8_t size;
  uint64_t counter;
} ros2_shm_demo__msg__ShmTopic;

// Struct for a sequence of ros2_shm_demo__msg__ShmTopic.
typedef struct ros2_shm_demo__msg__ShmTopic__Sequence
{
  ros2_shm_demo__msg__ShmTopic * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_shm_demo__msg__ShmTopic__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__STRUCT_H_
