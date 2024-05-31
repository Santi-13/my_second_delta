// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from more_interfaces:srv/DeltaTheta.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "more_interfaces/srv/detail/delta_theta__rosidl_typesupport_introspection_c.h"
#include "more_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "more_interfaces/srv/detail/delta_theta__functions.h"
#include "more_interfaces/srv/detail/delta_theta__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  more_interfaces__srv__DeltaTheta_Request__init(message_memory);
}

void more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_fini_function(void * message_memory)
{
  more_interfaces__srv__DeltaTheta_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(more_interfaces__srv__DeltaTheta_Request, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(more_interfaces__srv__DeltaTheta_Request, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(more_interfaces__srv__DeltaTheta_Request, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_message_members = {
  "more_interfaces__srv",  // message namespace
  "DeltaTheta_Request",  // message name
  3,  // number of fields
  sizeof(more_interfaces__srv__DeltaTheta_Request),
  more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_message_member_array,  // message members
  more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_message_type_support_handle = {
  0,
  &more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_message_members,
  get_message_typesupport_handle_function,
  &more_interfaces__srv__DeltaTheta_Request__get_type_hash,
  &more_interfaces__srv__DeltaTheta_Request__get_type_description,
  &more_interfaces__srv__DeltaTheta_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_more_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta_Request)() {
  if (!more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_message_type_support_handle.typesupport_identifier) {
    more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "more_interfaces/srv/detail/delta_theta__rosidl_typesupport_introspection_c.h"
// already included above
// #include "more_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "more_interfaces/srv/detail/delta_theta__functions.h"
// already included above
// #include "more_interfaces/srv/detail/delta_theta__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  more_interfaces__srv__DeltaTheta_Response__init(message_memory);
}

void more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_fini_function(void * message_memory)
{
  more_interfaces__srv__DeltaTheta_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_message_member_array[3] = {
  {
    "theta1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(more_interfaces__srv__DeltaTheta_Response, theta1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(more_interfaces__srv__DeltaTheta_Response, theta2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(more_interfaces__srv__DeltaTheta_Response, theta3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_message_members = {
  "more_interfaces__srv",  // message namespace
  "DeltaTheta_Response",  // message name
  3,  // number of fields
  sizeof(more_interfaces__srv__DeltaTheta_Response),
  more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_message_member_array,  // message members
  more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_message_type_support_handle = {
  0,
  &more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_message_members,
  get_message_typesupport_handle_function,
  &more_interfaces__srv__DeltaTheta_Response__get_type_hash,
  &more_interfaces__srv__DeltaTheta_Response__get_type_description,
  &more_interfaces__srv__DeltaTheta_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_more_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta_Response)() {
  if (!more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_message_type_support_handle.typesupport_identifier) {
    more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "more_interfaces/srv/detail/delta_theta__rosidl_typesupport_introspection_c.h"
// already included above
// #include "more_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "more_interfaces/srv/detail/delta_theta__functions.h"
// already included above
// #include "more_interfaces/srv/detail/delta_theta__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "more_interfaces/srv/delta_theta.h"
// Member `request`
// Member `response`
// already included above
// #include "more_interfaces/srv/detail/delta_theta__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  more_interfaces__srv__DeltaTheta_Event__init(message_memory);
}

void more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_fini_function(void * message_memory)
{
  more_interfaces__srv__DeltaTheta_Event__fini(message_memory);
}

size_t more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__size_function__DeltaTheta_Event__request(
  const void * untyped_member)
{
  const more_interfaces__srv__DeltaTheta_Request__Sequence * member =
    (const more_interfaces__srv__DeltaTheta_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_const_function__DeltaTheta_Event__request(
  const void * untyped_member, size_t index)
{
  const more_interfaces__srv__DeltaTheta_Request__Sequence * member =
    (const more_interfaces__srv__DeltaTheta_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_function__DeltaTheta_Event__request(
  void * untyped_member, size_t index)
{
  more_interfaces__srv__DeltaTheta_Request__Sequence * member =
    (more_interfaces__srv__DeltaTheta_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__fetch_function__DeltaTheta_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const more_interfaces__srv__DeltaTheta_Request * item =
    ((const more_interfaces__srv__DeltaTheta_Request *)
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_const_function__DeltaTheta_Event__request(untyped_member, index));
  more_interfaces__srv__DeltaTheta_Request * value =
    (more_interfaces__srv__DeltaTheta_Request *)(untyped_value);
  *value = *item;
}

void more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__assign_function__DeltaTheta_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  more_interfaces__srv__DeltaTheta_Request * item =
    ((more_interfaces__srv__DeltaTheta_Request *)
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_function__DeltaTheta_Event__request(untyped_member, index));
  const more_interfaces__srv__DeltaTheta_Request * value =
    (const more_interfaces__srv__DeltaTheta_Request *)(untyped_value);
  *item = *value;
}

bool more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__resize_function__DeltaTheta_Event__request(
  void * untyped_member, size_t size)
{
  more_interfaces__srv__DeltaTheta_Request__Sequence * member =
    (more_interfaces__srv__DeltaTheta_Request__Sequence *)(untyped_member);
  more_interfaces__srv__DeltaTheta_Request__Sequence__fini(member);
  return more_interfaces__srv__DeltaTheta_Request__Sequence__init(member, size);
}

size_t more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__size_function__DeltaTheta_Event__response(
  const void * untyped_member)
{
  const more_interfaces__srv__DeltaTheta_Response__Sequence * member =
    (const more_interfaces__srv__DeltaTheta_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_const_function__DeltaTheta_Event__response(
  const void * untyped_member, size_t index)
{
  const more_interfaces__srv__DeltaTheta_Response__Sequence * member =
    (const more_interfaces__srv__DeltaTheta_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_function__DeltaTheta_Event__response(
  void * untyped_member, size_t index)
{
  more_interfaces__srv__DeltaTheta_Response__Sequence * member =
    (more_interfaces__srv__DeltaTheta_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__fetch_function__DeltaTheta_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const more_interfaces__srv__DeltaTheta_Response * item =
    ((const more_interfaces__srv__DeltaTheta_Response *)
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_const_function__DeltaTheta_Event__response(untyped_member, index));
  more_interfaces__srv__DeltaTheta_Response * value =
    (more_interfaces__srv__DeltaTheta_Response *)(untyped_value);
  *value = *item;
}

void more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__assign_function__DeltaTheta_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  more_interfaces__srv__DeltaTheta_Response * item =
    ((more_interfaces__srv__DeltaTheta_Response *)
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_function__DeltaTheta_Event__response(untyped_member, index));
  const more_interfaces__srv__DeltaTheta_Response * value =
    (const more_interfaces__srv__DeltaTheta_Response *)(untyped_value);
  *item = *value;
}

bool more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__resize_function__DeltaTheta_Event__response(
  void * untyped_member, size_t size)
{
  more_interfaces__srv__DeltaTheta_Response__Sequence * member =
    (more_interfaces__srv__DeltaTheta_Response__Sequence *)(untyped_member);
  more_interfaces__srv__DeltaTheta_Response__Sequence__fini(member);
  return more_interfaces__srv__DeltaTheta_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(more_interfaces__srv__DeltaTheta_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(more_interfaces__srv__DeltaTheta_Event, request),  // bytes offset in struct
    NULL,  // default value
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__size_function__DeltaTheta_Event__request,  // size() function pointer
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_const_function__DeltaTheta_Event__request,  // get_const(index) function pointer
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_function__DeltaTheta_Event__request,  // get(index) function pointer
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__fetch_function__DeltaTheta_Event__request,  // fetch(index, &value) function pointer
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__assign_function__DeltaTheta_Event__request,  // assign(index, value) function pointer
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__resize_function__DeltaTheta_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(more_interfaces__srv__DeltaTheta_Event, response),  // bytes offset in struct
    NULL,  // default value
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__size_function__DeltaTheta_Event__response,  // size() function pointer
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_const_function__DeltaTheta_Event__response,  // get_const(index) function pointer
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__get_function__DeltaTheta_Event__response,  // get(index) function pointer
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__fetch_function__DeltaTheta_Event__response,  // fetch(index, &value) function pointer
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__assign_function__DeltaTheta_Event__response,  // assign(index, value) function pointer
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__resize_function__DeltaTheta_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_members = {
  "more_interfaces__srv",  // message namespace
  "DeltaTheta_Event",  // message name
  3,  // number of fields
  sizeof(more_interfaces__srv__DeltaTheta_Event),
  more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_member_array,  // message members
  more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_type_support_handle = {
  0,
  &more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_members,
  get_message_typesupport_handle_function,
  &more_interfaces__srv__DeltaTheta_Event__get_type_hash,
  &more_interfaces__srv__DeltaTheta_Event__get_type_description,
  &more_interfaces__srv__DeltaTheta_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_more_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta_Event)() {
  more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta_Request)();
  more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta_Response)();
  if (!more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_type_support_handle.typesupport_identifier) {
    more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "more_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "more_interfaces/srv/detail/delta_theta__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers more_interfaces__srv__detail__delta_theta__rosidl_typesupport_introspection_c__DeltaTheta_service_members = {
  "more_interfaces__srv",  // service namespace
  "DeltaTheta",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // more_interfaces__srv__detail__delta_theta__rosidl_typesupport_introspection_c__DeltaTheta_Request_message_type_support_handle,
  NULL,  // response message
  // more_interfaces__srv__detail__delta_theta__rosidl_typesupport_introspection_c__DeltaTheta_Response_message_type_support_handle
  NULL  // event_message
  // more_interfaces__srv__detail__delta_theta__rosidl_typesupport_introspection_c__DeltaTheta_Response_message_type_support_handle
};


static rosidl_service_type_support_t more_interfaces__srv__detail__delta_theta__rosidl_typesupport_introspection_c__DeltaTheta_service_type_support_handle = {
  0,
  &more_interfaces__srv__detail__delta_theta__rosidl_typesupport_introspection_c__DeltaTheta_service_members,
  get_service_typesupport_handle_function,
  &more_interfaces__srv__DeltaTheta_Request__rosidl_typesupport_introspection_c__DeltaTheta_Request_message_type_support_handle,
  &more_interfaces__srv__DeltaTheta_Response__rosidl_typesupport_introspection_c__DeltaTheta_Response_message_type_support_handle,
  &more_interfaces__srv__DeltaTheta_Event__rosidl_typesupport_introspection_c__DeltaTheta_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    more_interfaces,
    srv,
    DeltaTheta
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    more_interfaces,
    srv,
    DeltaTheta
  ),
  &more_interfaces__srv__DeltaTheta__get_type_hash,
  &more_interfaces__srv__DeltaTheta__get_type_description,
  &more_interfaces__srv__DeltaTheta__get_type_description_sources,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta_Response)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta_Event)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_more_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta)() {
  if (!more_interfaces__srv__detail__delta_theta__rosidl_typesupport_introspection_c__DeltaTheta_service_type_support_handle.typesupport_identifier) {
    more_interfaces__srv__detail__delta_theta__rosidl_typesupport_introspection_c__DeltaTheta_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)more_interfaces__srv__detail__delta_theta__rosidl_typesupport_introspection_c__DeltaTheta_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, srv, DeltaTheta_Event)()->data;
  }

  return &more_interfaces__srv__detail__delta_theta__rosidl_typesupport_introspection_c__DeltaTheta_service_type_support_handle;
}