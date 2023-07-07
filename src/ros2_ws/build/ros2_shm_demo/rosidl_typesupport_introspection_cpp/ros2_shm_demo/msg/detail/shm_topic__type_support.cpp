// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ros2_shm_demo:msg/ShmTopic.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ros2_shm_demo/msg/detail/shm_topic__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ros2_shm_demo
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ShmTopic_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ros2_shm_demo::msg::ShmTopic(_init);
}

void ShmTopic_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ros2_shm_demo::msg::ShmTopic *>(message_memory);
  typed_message->~ShmTopic();
}

size_t size_function__ShmTopic__data(const void * untyped_member)
{
  (void)untyped_member;
  return 256;
}

const void * get_const_function__ShmTopic__data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 256> *>(untyped_member);
  return &member[index];
}

void * get_function__ShmTopic__data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 256> *>(untyped_member);
  return &member[index];
}

void fetch_function__ShmTopic__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__ShmTopic__data(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__ShmTopic__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__ShmTopic__data(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ShmTopic_message_member_array[3] = {
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    256,  // array size
    false,  // is upper bound
    offsetof(ros2_shm_demo::msg::ShmTopic, data),  // bytes offset in struct
    nullptr,  // default value
    size_function__ShmTopic__data,  // size() function pointer
    get_const_function__ShmTopic__data,  // get_const(index) function pointer
    get_function__ShmTopic__data,  // get(index) function pointer
    fetch_function__ShmTopic__data,  // fetch(index, &value) function pointer
    assign_function__ShmTopic__data,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "size",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_shm_demo::msg::ShmTopic, size),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "counter",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_shm_demo::msg::ShmTopic, counter),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ShmTopic_message_members = {
  "ros2_shm_demo::msg",  // message namespace
  "ShmTopic",  // message name
  3,  // number of fields
  sizeof(ros2_shm_demo::msg::ShmTopic),
  ShmTopic_message_member_array,  // message members
  ShmTopic_init_function,  // function to initialize message memory (memory has to be allocated)
  ShmTopic_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ShmTopic_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ShmTopic_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ros2_shm_demo


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_shm_demo::msg::ShmTopic>()
{
  return &::ros2_shm_demo::msg::rosidl_typesupport_introspection_cpp::ShmTopic_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_shm_demo, msg, ShmTopic)() {
  return &::ros2_shm_demo::msg::rosidl_typesupport_introspection_cpp::ShmTopic_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
