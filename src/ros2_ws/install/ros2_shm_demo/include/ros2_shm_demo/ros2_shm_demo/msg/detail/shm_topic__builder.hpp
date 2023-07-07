// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_shm_demo:msg/ShmTopic.idl
// generated code does not contain a copyright notice

#ifndef ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__BUILDER_HPP_
#define ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_shm_demo/msg/detail/shm_topic__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_shm_demo
{

namespace msg
{

namespace builder
{

class Init_ShmTopic_counter
{
public:
  explicit Init_ShmTopic_counter(::ros2_shm_demo::msg::ShmTopic & msg)
  : msg_(msg)
  {}
  ::ros2_shm_demo::msg::ShmTopic counter(::ros2_shm_demo::msg::ShmTopic::_counter_type arg)
  {
    msg_.counter = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_shm_demo::msg::ShmTopic msg_;
};

class Init_ShmTopic_size
{
public:
  explicit Init_ShmTopic_size(::ros2_shm_demo::msg::ShmTopic & msg)
  : msg_(msg)
  {}
  Init_ShmTopic_counter size(::ros2_shm_demo::msg::ShmTopic::_size_type arg)
  {
    msg_.size = std::move(arg);
    return Init_ShmTopic_counter(msg_);
  }

private:
  ::ros2_shm_demo::msg::ShmTopic msg_;
};

class Init_ShmTopic_data
{
public:
  Init_ShmTopic_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ShmTopic_size data(::ros2_shm_demo::msg::ShmTopic::_data_type arg)
  {
    msg_.data = std::move(arg);
    return Init_ShmTopic_size(msg_);
  }

private:
  ::ros2_shm_demo::msg::ShmTopic msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_shm_demo::msg::ShmTopic>()
{
  return ros2_shm_demo::msg::builder::Init_ShmTopic_data();
}

}  // namespace ros2_shm_demo

#endif  // ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__BUILDER_HPP_
