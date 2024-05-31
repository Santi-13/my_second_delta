// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from more_interfaces:srv/DeltaTheta.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__SRV__DETAIL__DELTA_THETA__BUILDER_HPP_
#define MORE_INTERFACES__SRV__DETAIL__DELTA_THETA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "more_interfaces/srv/detail/delta_theta__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace more_interfaces
{

namespace srv
{

namespace builder
{

class Init_DeltaTheta_Request_z
{
public:
  explicit Init_DeltaTheta_Request_z(::more_interfaces::srv::DeltaTheta_Request & msg)
  : msg_(msg)
  {}
  ::more_interfaces::srv::DeltaTheta_Request z(::more_interfaces::srv::DeltaTheta_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::more_interfaces::srv::DeltaTheta_Request msg_;
};

class Init_DeltaTheta_Request_y
{
public:
  explicit Init_DeltaTheta_Request_y(::more_interfaces::srv::DeltaTheta_Request & msg)
  : msg_(msg)
  {}
  Init_DeltaTheta_Request_z y(::more_interfaces::srv::DeltaTheta_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_DeltaTheta_Request_z(msg_);
  }

private:
  ::more_interfaces::srv::DeltaTheta_Request msg_;
};

class Init_DeltaTheta_Request_x
{
public:
  Init_DeltaTheta_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeltaTheta_Request_y x(::more_interfaces::srv::DeltaTheta_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_DeltaTheta_Request_y(msg_);
  }

private:
  ::more_interfaces::srv::DeltaTheta_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::more_interfaces::srv::DeltaTheta_Request>()
{
  return more_interfaces::srv::builder::Init_DeltaTheta_Request_x();
}

}  // namespace more_interfaces


namespace more_interfaces
{

namespace srv
{

namespace builder
{

class Init_DeltaTheta_Response_theta3
{
public:
  explicit Init_DeltaTheta_Response_theta3(::more_interfaces::srv::DeltaTheta_Response & msg)
  : msg_(msg)
  {}
  ::more_interfaces::srv::DeltaTheta_Response theta3(::more_interfaces::srv::DeltaTheta_Response::_theta3_type arg)
  {
    msg_.theta3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::more_interfaces::srv::DeltaTheta_Response msg_;
};

class Init_DeltaTheta_Response_theta2
{
public:
  explicit Init_DeltaTheta_Response_theta2(::more_interfaces::srv::DeltaTheta_Response & msg)
  : msg_(msg)
  {}
  Init_DeltaTheta_Response_theta3 theta2(::more_interfaces::srv::DeltaTheta_Response::_theta2_type arg)
  {
    msg_.theta2 = std::move(arg);
    return Init_DeltaTheta_Response_theta3(msg_);
  }

private:
  ::more_interfaces::srv::DeltaTheta_Response msg_;
};

class Init_DeltaTheta_Response_theta1
{
public:
  Init_DeltaTheta_Response_theta1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeltaTheta_Response_theta2 theta1(::more_interfaces::srv::DeltaTheta_Response::_theta1_type arg)
  {
    msg_.theta1 = std::move(arg);
    return Init_DeltaTheta_Response_theta2(msg_);
  }

private:
  ::more_interfaces::srv::DeltaTheta_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::more_interfaces::srv::DeltaTheta_Response>()
{
  return more_interfaces::srv::builder::Init_DeltaTheta_Response_theta1();
}

}  // namespace more_interfaces


namespace more_interfaces
{

namespace srv
{

namespace builder
{

class Init_DeltaTheta_Event_response
{
public:
  explicit Init_DeltaTheta_Event_response(::more_interfaces::srv::DeltaTheta_Event & msg)
  : msg_(msg)
  {}
  ::more_interfaces::srv::DeltaTheta_Event response(::more_interfaces::srv::DeltaTheta_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::more_interfaces::srv::DeltaTheta_Event msg_;
};

class Init_DeltaTheta_Event_request
{
public:
  explicit Init_DeltaTheta_Event_request(::more_interfaces::srv::DeltaTheta_Event & msg)
  : msg_(msg)
  {}
  Init_DeltaTheta_Event_response request(::more_interfaces::srv::DeltaTheta_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_DeltaTheta_Event_response(msg_);
  }

private:
  ::more_interfaces::srv::DeltaTheta_Event msg_;
};

class Init_DeltaTheta_Event_info
{
public:
  Init_DeltaTheta_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeltaTheta_Event_request info(::more_interfaces::srv::DeltaTheta_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_DeltaTheta_Event_request(msg_);
  }

private:
  ::more_interfaces::srv::DeltaTheta_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::more_interfaces::srv::DeltaTheta_Event>()
{
  return more_interfaces::srv::builder::Init_DeltaTheta_Event_info();
}

}  // namespace more_interfaces

#endif  // MORE_INTERFACES__SRV__DETAIL__DELTA_THETA__BUILDER_HPP_
