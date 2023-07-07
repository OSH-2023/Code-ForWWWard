// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros2_shm_demo:msg/ShmTopic.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros2_shm_demo/msg/detail/shm_topic__rosidl_typesupport_introspection_c.h"
#include "ros2_shm_demo/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros2_shm_demo/msg/detail/shm_topic__functions.h"
#include "ros2_shm_demo/msg/detail/shm_topic__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_shm_demo__msg__ShmTopic__init(message_memory);
}

void ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_fini_function(void * message_memory)
{
  ros2_shm_demo__msg__ShmTopic__fini(message_memory);
}

size_t ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__size_function__ShmTopic__data(
  const void * untyped_member)
{
  (void)untyped_member;
  return 256;
}

const void * ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__get_const_function__ShmTopic__data(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__get_function__ShmTopic__data(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__fetch_function__ShmTopic__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__get_const_function__ShmTopic__data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__assign_function__ShmTopic__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__get_function__ShmTopic__data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_message_member_array[3] = {
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    256,  // array size
    false,  // is upper bound
    offsetof(ros2_shm_demo__msg__ShmTopic, data),  // bytes offset in struct
    NULL,  // default value
    ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__size_function__ShmTopic__data,  // size() function pointer
    ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__get_const_function__ShmTopic__data,  // get_const(index) function pointer
    ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__get_function__ShmTopic__data,  // get(index) function pointer
    ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__fetch_function__ShmTopic__data,  // fetch(index, &value) function pointer
    ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__assign_function__ShmTopic__data,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_shm_demo__msg__ShmTopic, size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "counter",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_shm_demo__msg__ShmTopic, counter),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_message_members = {
  "ros2_shm_demo__msg",  // message namespace
  "ShmTopic",  // message name
  3,  // number of fields
  sizeof(ros2_shm_demo__msg__ShmTopic),
  ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_message_member_array,  // message members
  ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_init_function,  // function to initialize message memory (memory has to be allocated)
  ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_message_type_support_handle = {
  0,
  &ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_shm_demo
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_shm_demo, msg, ShmTopic)() {
  if (!ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_message_type_support_handle.typesupport_identifier) {
    ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros2_shm_demo__msg__ShmTopic__rosidl_typesupport_introspection_c__ShmTopic_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
