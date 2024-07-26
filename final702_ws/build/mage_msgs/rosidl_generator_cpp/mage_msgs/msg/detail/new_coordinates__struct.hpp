// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mage_msgs:msg/NewCoordinates.idl
// generated code does not contain a copyright notice

#ifndef MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__STRUCT_HPP_
#define MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__mage_msgs__msg__NewCoordinates __attribute__((deprecated))
#else
# define DEPRECATED__mage_msgs__msg__NewCoordinates __declspec(deprecated)
#endif

namespace mage_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NewCoordinates_
{
  using Type = NewCoordinates_<ContainerAllocator>;

  explicit NewCoordinates_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_coordinate = 0.0;
      this->y_coordinate = 0.0;
    }
  }

  explicit NewCoordinates_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_coordinate = 0.0;
      this->y_coordinate = 0.0;
    }
  }

  // field types and members
  using _x_coordinate_type =
    double;
  _x_coordinate_type x_coordinate;
  using _y_coordinate_type =
    double;
  _y_coordinate_type y_coordinate;

  // setters for named parameter idiom
  Type & set__x_coordinate(
    const double & _arg)
  {
    this->x_coordinate = _arg;
    return *this;
  }
  Type & set__y_coordinate(
    const double & _arg)
  {
    this->y_coordinate = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mage_msgs::msg::NewCoordinates_<ContainerAllocator> *;
  using ConstRawPtr =
    const mage_msgs::msg::NewCoordinates_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mage_msgs::msg::NewCoordinates_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mage_msgs::msg::NewCoordinates_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mage_msgs::msg::NewCoordinates_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mage_msgs::msg::NewCoordinates_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mage_msgs::msg::NewCoordinates_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mage_msgs::msg::NewCoordinates_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mage_msgs::msg::NewCoordinates_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mage_msgs::msg::NewCoordinates_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mage_msgs__msg__NewCoordinates
    std::shared_ptr<mage_msgs::msg::NewCoordinates_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mage_msgs__msg__NewCoordinates
    std::shared_ptr<mage_msgs::msg::NewCoordinates_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NewCoordinates_ & other) const
  {
    if (this->x_coordinate != other.x_coordinate) {
      return false;
    }
    if (this->y_coordinate != other.y_coordinate) {
      return false;
    }
    return true;
  }
  bool operator!=(const NewCoordinates_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NewCoordinates_

// alias to use template instance with default allocator
using NewCoordinates =
  mage_msgs::msg::NewCoordinates_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mage_msgs

#endif  // MAGE_MSGS__MSG__DETAIL__NEW_COORDINATES__STRUCT_HPP_
