// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_shm_demo:msg/ShmTopic.idl
// generated code does not contain a copyright notice

#ifndef ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__TRAITS_HPP_
#define ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_shm_demo/msg/detail/shm_topic__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_shm_demo
{

namespace msg
{

inline void to_flow_style_yaml(
  const ShmTopic & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: size
  {
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << ", ";
  }

  // member: counter
  {
    out << "counter: ";
    rosidl_generator_traits::value_to_yaml(msg.counter, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ShmTopic & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << "\n";
  }

  // member: counter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "counter: ";
    rosidl_generator_traits::value_to_yaml(msg.counter, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ShmTopic & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ros2_shm_demo

namespace rosidl_generator_traits
{

[[deprecated("use ros2_shm_demo::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_shm_demo::msg::ShmTopic & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_shm_demo::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_shm_demo::msg::to_yaml() instead")]]
inline std::string to_yaml(const ros2_shm_demo::msg::ShmTopic & msg)
{
  return ros2_shm_demo::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_shm_demo::msg::ShmTopic>()
{
  return "ros2_shm_demo::msg::ShmTopic";
}

template<>
inline const char * name<ros2_shm_demo::msg::ShmTopic>()
{
  return "ros2_shm_demo/msg/ShmTopic";
}

template<>
struct has_fixed_size<ros2_shm_demo::msg::ShmTopic>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_shm_demo::msg::ShmTopic>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_shm_demo::msg::ShmTopic>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__TRAITS_HPP_
