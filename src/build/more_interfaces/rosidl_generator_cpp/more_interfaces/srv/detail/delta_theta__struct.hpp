// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from more_interfaces:srv/DeltaTheta.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__SRV__DETAIL__DELTA_THETA__STRUCT_HPP_
#define MORE_INTERFACES__SRV__DETAIL__DELTA_THETA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__more_interfaces__srv__DeltaTheta_Request __attribute__((deprecated))
#else
# define DEPRECATED__more_interfaces__srv__DeltaTheta_Request __declspec(deprecated)
#endif

namespace more_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeltaTheta_Request_
{
  using Type = DeltaTheta_Request_<ContainerAllocator>;

  explicit DeltaTheta_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  explicit DeltaTheta_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__more_interfaces__srv__DeltaTheta_Request
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__more_interfaces__srv__DeltaTheta_Request
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeltaTheta_Request_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeltaTheta_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeltaTheta_Request_

// alias to use template instance with default allocator
using DeltaTheta_Request =
  more_interfaces::srv::DeltaTheta_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace more_interfaces


#ifndef _WIN32
# define DEPRECATED__more_interfaces__srv__DeltaTheta_Response __attribute__((deprecated))
#else
# define DEPRECATED__more_interfaces__srv__DeltaTheta_Response __declspec(deprecated)
#endif

namespace more_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeltaTheta_Response_
{
  using Type = DeltaTheta_Response_<ContainerAllocator>;

  explicit DeltaTheta_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->theta1 = 0.0;
      this->theta2 = 0.0;
      this->theta3 = 0.0;
    }
  }

  explicit DeltaTheta_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->theta1 = 0.0;
      this->theta2 = 0.0;
      this->theta3 = 0.0;
    }
  }

  // field types and members
  using _theta1_type =
    double;
  _theta1_type theta1;
  using _theta2_type =
    double;
  _theta2_type theta2;
  using _theta3_type =
    double;
  _theta3_type theta3;

  // setters for named parameter idiom
  Type & set__theta1(
    const double & _arg)
  {
    this->theta1 = _arg;
    return *this;
  }
  Type & set__theta2(
    const double & _arg)
  {
    this->theta2 = _arg;
    return *this;
  }
  Type & set__theta3(
    const double & _arg)
  {
    this->theta3 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__more_interfaces__srv__DeltaTheta_Response
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__more_interfaces__srv__DeltaTheta_Response
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeltaTheta_Response_ & other) const
  {
    if (this->theta1 != other.theta1) {
      return false;
    }
    if (this->theta2 != other.theta2) {
      return false;
    }
    if (this->theta3 != other.theta3) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeltaTheta_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeltaTheta_Response_

// alias to use template instance with default allocator
using DeltaTheta_Response =
  more_interfaces::srv::DeltaTheta_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace more_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__more_interfaces__srv__DeltaTheta_Event __attribute__((deprecated))
#else
# define DEPRECATED__more_interfaces__srv__DeltaTheta_Event __declspec(deprecated)
#endif

namespace more_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeltaTheta_Event_
{
  using Type = DeltaTheta_Event_<ContainerAllocator>;

  explicit DeltaTheta_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit DeltaTheta_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<more_interfaces::srv::DeltaTheta_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<more_interfaces::srv::DeltaTheta_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__more_interfaces__srv__DeltaTheta_Event
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__more_interfaces__srv__DeltaTheta_Event
    std::shared_ptr<more_interfaces::srv::DeltaTheta_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeltaTheta_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeltaTheta_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeltaTheta_Event_

// alias to use template instance with default allocator
using DeltaTheta_Event =
  more_interfaces::srv::DeltaTheta_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace more_interfaces

namespace more_interfaces
{

namespace srv
{

struct DeltaTheta
{
  using Request = more_interfaces::srv::DeltaTheta_Request;
  using Response = more_interfaces::srv::DeltaTheta_Response;
  using Event = more_interfaces::srv::DeltaTheta_Event;
};

}  // namespace srv

}  // namespace more_interfaces

#endif  // MORE_INTERFACES__SRV__DETAIL__DELTA_THETA__STRUCT_HPP_
