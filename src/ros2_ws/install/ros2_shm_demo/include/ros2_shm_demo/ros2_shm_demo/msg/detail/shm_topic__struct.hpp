// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_shm_demo:msg/ShmTopic.idl
// generated code does not contain a copyright notice

#ifndef ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__STRUCT_HPP_
#define ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_shm_demo__msg__ShmTopic __attribute__((deprecated))
#else
# define DEPRECATED__ros2_shm_demo__msg__ShmTopic __declspec(deprecated)
#endif

namespace ros2_shm_demo
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ShmTopic_
{
  using Type = ShmTopic_<ContainerAllocator>;

  explicit ShmTopic_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 256>::iterator, uint8_t>(this->data.begin(), this->data.end(), 0);
      this->size = 0;
      this->counter = 0ull;
    }
  }

  explicit ShmTopic_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 256>::iterator, uint8_t>(this->data.begin(), this->data.end(), 0);
      this->size = 0;
      this->counter = 0ull;
    }
  }

  // field types and members
  using _data_type =
    std::array<uint8_t, 256>;
  _data_type data;
  using _size_type =
    uint8_t;
  _size_type size;
  using _counter_type =
    uint64_t;
  _counter_type counter;

  // setters for named parameter idiom
  Type & set__data(
    const std::array<uint8_t, 256> & _arg)
  {
    this->data = _arg;
    return *this;
  }
  Type & set__size(
    const uint8_t & _arg)
  {
    this->size = _arg;
    return *this;
  }
  Type & set__counter(
    const uint64_t & _arg)
  {
    this->counter = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t MAX_SIZE =
    255u;

  // pointer types
  using RawPtr =
    ros2_shm_demo::msg::ShmTopic_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_shm_demo::msg::ShmTopic_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_shm_demo::msg::ShmTopic_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_shm_demo::msg::ShmTopic_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_shm_demo::msg::ShmTopic_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_shm_demo::msg::ShmTopic_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_shm_demo::msg::ShmTopic_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_shm_demo::msg::ShmTopic_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_shm_demo::msg::ShmTopic_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_shm_demo::msg::ShmTopic_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_shm_demo__msg__ShmTopic
    std::shared_ptr<ros2_shm_demo::msg::ShmTopic_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_shm_demo__msg__ShmTopic
    std::shared_ptr<ros2_shm_demo::msg::ShmTopic_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ShmTopic_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    if (this->size != other.size) {
      return false;
    }
    if (this->counter != other.counter) {
      return false;
    }
    return true;
  }
  bool operator!=(const ShmTopic_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ShmTopic_

// alias to use template instance with default allocator
using ShmTopic =
  ros2_shm_demo::msg::ShmTopic_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr uint8_t ShmTopic_<ContainerAllocator>::MAX_SIZE;

}  // namespace msg

}  // namespace ros2_shm_demo

#endif  // ROS2_SHM_DEMO__MSG__DETAIL__SHM_TOPIC__STRUCT_HPP_
