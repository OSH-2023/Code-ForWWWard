// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2_shm_demo:msg/ShmTopic.idl
// generated code does not contain a copyright notice
#include "ros2_shm_demo/msg/detail/shm_topic__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2_shm_demo/msg/detail/shm_topic__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ros2_shm_demo
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_shm_demo
cdr_serialize(
  const ros2_shm_demo::msg::ShmTopic & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: data
  {
    cdr << ros_message.data;
  }
  // Member: size
  cdr << ros_message.size;
  // Member: counter
  cdr << ros_message.counter;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_shm_demo
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2_shm_demo::msg::ShmTopic & ros_message)
{
  // Member: data
  {
    cdr >> ros_message.data;
  }

  // Member: size
  cdr >> ros_message.size;

  // Member: counter
  cdr >> ros_message.counter;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_shm_demo
get_serialized_size(
  const ros2_shm_demo::msg::ShmTopic & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: data
  {
    size_t array_size = 256;
    size_t item_size = sizeof(ros_message.data[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: size
  {
    size_t item_size = sizeof(ros_message.size);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: counter
  {
    size_t item_size = sizeof(ros_message.counter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_shm_demo
max_serialized_size_ShmTopic(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: data
  {
    size_t array_size = 256;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: size
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: counter
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _ShmTopic__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2_shm_demo::msg::ShmTopic *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ShmTopic__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2_shm_demo::msg::ShmTopic *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ShmTopic__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2_shm_demo::msg::ShmTopic *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ShmTopic__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ShmTopic(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ShmTopic__callbacks = {
  "ros2_shm_demo::msg",
  "ShmTopic",
  _ShmTopic__cdr_serialize,
  _ShmTopic__cdr_deserialize,
  _ShmTopic__get_serialized_size,
  _ShmTopic__max_serialized_size
};

static rosidl_message_type_support_t _ShmTopic__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ShmTopic__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ros2_shm_demo

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2_shm_demo
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_shm_demo::msg::ShmTopic>()
{
  return &ros2_shm_demo::msg::typesupport_fastrtps_cpp::_ShmTopic__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_shm_demo, msg, ShmTopic)() {
  return &ros2_shm_demo::msg::typesupport_fastrtps_cpp::_ShmTopic__handle;
}

#ifdef __cplusplus
}
#endif
