// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from more_interfaces:srv/DeltaTheta.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__SRV__DETAIL__DELTA_THETA__STRUCT_H_
#define MORE_INTERFACES__SRV__DETAIL__DELTA_THETA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DeltaTheta in the package more_interfaces.
typedef struct more_interfaces__srv__DeltaTheta_Request
{
  double x;
  double y;
  double z;
} more_interfaces__srv__DeltaTheta_Request;

// Struct for a sequence of more_interfaces__srv__DeltaTheta_Request.
typedef struct more_interfaces__srv__DeltaTheta_Request__Sequence
{
  more_interfaces__srv__DeltaTheta_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} more_interfaces__srv__DeltaTheta_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/DeltaTheta in the package more_interfaces.
typedef struct more_interfaces__srv__DeltaTheta_Response
{
  double theta1;
  double theta2;
  double theta3;
} more_interfaces__srv__DeltaTheta_Response;

// Struct for a sequence of more_interfaces__srv__DeltaTheta_Response.
typedef struct more_interfaces__srv__DeltaTheta_Response__Sequence
{
  more_interfaces__srv__DeltaTheta_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} more_interfaces__srv__DeltaTheta_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  more_interfaces__srv__DeltaTheta_Event__request__MAX_SIZE = 1
};
// response
enum
{
  more_interfaces__srv__DeltaTheta_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/DeltaTheta in the package more_interfaces.
typedef struct more_interfaces__srv__DeltaTheta_Event
{
  service_msgs__msg__ServiceEventInfo info;
  more_interfaces__srv__DeltaTheta_Request__Sequence request;
  more_interfaces__srv__DeltaTheta_Response__Sequence response;
} more_interfaces__srv__DeltaTheta_Event;

// Struct for a sequence of more_interfaces__srv__DeltaTheta_Event.
typedef struct more_interfaces__srv__DeltaTheta_Event__Sequence
{
  more_interfaces__srv__DeltaTheta_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} more_interfaces__srv__DeltaTheta_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MORE_INTERFACES__SRV__DETAIL__DELTA_THETA__STRUCT_H_
