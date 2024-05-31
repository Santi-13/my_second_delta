// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from more_interfaces:srv/DeltaTheta.idl
// generated code does not contain a copyright notice

#include "more_interfaces/srv/detail/delta_theta__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
const rosidl_type_hash_t *
more_interfaces__srv__DeltaTheta__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x6f, 0x21, 0xc2, 0x4e, 0xde, 0xd0, 0xfa, 0x6c,
      0x94, 0x60, 0x9c, 0xe3, 0x39, 0x14, 0x05, 0x3c,
      0xc3, 0xf9, 0xf7, 0x9a, 0xde, 0xcc, 0x4d, 0xdd,
      0x04, 0xfb, 0x5b, 0x9f, 0x3f, 0xf6, 0x03, 0xa4,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
const rosidl_type_hash_t *
more_interfaces__srv__DeltaTheta_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x64, 0x62, 0x38, 0xf4, 0x65, 0x12, 0x15, 0xf4,
      0x0d, 0x7d, 0x5a, 0x49, 0xfa, 0xa4, 0xda, 0x0d,
      0x85, 0x24, 0x3d, 0xfe, 0x18, 0xd2, 0xfd, 0xc1,
      0xa8, 0x7f, 0xaa, 0xd7, 0x06, 0x2e, 0x65, 0xb4,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
const rosidl_type_hash_t *
more_interfaces__srv__DeltaTheta_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf7, 0x99, 0x73, 0xfd, 0x93, 0xaf, 0xb3, 0x85,
      0x05, 0x2b, 0xd8, 0x50, 0xe4, 0x46, 0x29, 0x64,
      0xb1, 0x08, 0x75, 0x4f, 0xf2, 0x6a, 0x56, 0x92,
      0xf4, 0xde, 0x37, 0x29, 0x80, 0xb3, 0xe4, 0xcb,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
const rosidl_type_hash_t *
more_interfaces__srv__DeltaTheta_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x76, 0x69, 0xdd, 0x5d, 0x83, 0xb0, 0xfa, 0x3a,
      0xc7, 0x96, 0xde, 0xac, 0xa7, 0xdd, 0x60, 0x26,
      0x28, 0xed, 0x94, 0xda, 0xf0, 0x6d, 0x75, 0x5e,
      0x27, 0xcb, 0x36, 0xf8, 0x25, 0x8b, 0x16, 0xe9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char more_interfaces__srv__DeltaTheta__TYPE_NAME[] = "more_interfaces/srv/DeltaTheta";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char more_interfaces__srv__DeltaTheta_Event__TYPE_NAME[] = "more_interfaces/srv/DeltaTheta_Event";
static char more_interfaces__srv__DeltaTheta_Request__TYPE_NAME[] = "more_interfaces/srv/DeltaTheta_Request";
static char more_interfaces__srv__DeltaTheta_Response__TYPE_NAME[] = "more_interfaces/srv/DeltaTheta_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char more_interfaces__srv__DeltaTheta__FIELD_NAME__request_message[] = "request_message";
static char more_interfaces__srv__DeltaTheta__FIELD_NAME__response_message[] = "response_message";
static char more_interfaces__srv__DeltaTheta__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field more_interfaces__srv__DeltaTheta__FIELDS[] = {
  {
    {more_interfaces__srv__DeltaTheta__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {more_interfaces__srv__DeltaTheta_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {more_interfaces__srv__DeltaTheta_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {more_interfaces__srv__DeltaTheta_Event__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription more_interfaces__srv__DeltaTheta__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta_Event__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
more_interfaces__srv__DeltaTheta__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {more_interfaces__srv__DeltaTheta__TYPE_NAME, 30, 30},
      {more_interfaces__srv__DeltaTheta__FIELDS, 3, 3},
    },
    {more_interfaces__srv__DeltaTheta__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = more_interfaces__srv__DeltaTheta_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = more_interfaces__srv__DeltaTheta_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = more_interfaces__srv__DeltaTheta_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char more_interfaces__srv__DeltaTheta_Request__FIELD_NAME__x[] = "x";
static char more_interfaces__srv__DeltaTheta_Request__FIELD_NAME__y[] = "y";
static char more_interfaces__srv__DeltaTheta_Request__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field more_interfaces__srv__DeltaTheta_Request__FIELDS[] = {
  {
    {more_interfaces__srv__DeltaTheta_Request__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta_Request__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta_Request__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
more_interfaces__srv__DeltaTheta_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {more_interfaces__srv__DeltaTheta_Request__TYPE_NAME, 38, 38},
      {more_interfaces__srv__DeltaTheta_Request__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char more_interfaces__srv__DeltaTheta_Response__FIELD_NAME__theta1[] = "theta1";
static char more_interfaces__srv__DeltaTheta_Response__FIELD_NAME__theta2[] = "theta2";
static char more_interfaces__srv__DeltaTheta_Response__FIELD_NAME__theta3[] = "theta3";

static rosidl_runtime_c__type_description__Field more_interfaces__srv__DeltaTheta_Response__FIELDS[] = {
  {
    {more_interfaces__srv__DeltaTheta_Response__FIELD_NAME__theta1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta_Response__FIELD_NAME__theta2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta_Response__FIELD_NAME__theta3, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
more_interfaces__srv__DeltaTheta_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {more_interfaces__srv__DeltaTheta_Response__TYPE_NAME, 39, 39},
      {more_interfaces__srv__DeltaTheta_Response__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char more_interfaces__srv__DeltaTheta_Event__FIELD_NAME__info[] = "info";
static char more_interfaces__srv__DeltaTheta_Event__FIELD_NAME__request[] = "request";
static char more_interfaces__srv__DeltaTheta_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field more_interfaces__srv__DeltaTheta_Event__FIELDS[] = {
  {
    {more_interfaces__srv__DeltaTheta_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {more_interfaces__srv__DeltaTheta_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {more_interfaces__srv__DeltaTheta_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription more_interfaces__srv__DeltaTheta_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {more_interfaces__srv__DeltaTheta_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
more_interfaces__srv__DeltaTheta_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {more_interfaces__srv__DeltaTheta_Event__TYPE_NAME, 36, 36},
      {more_interfaces__srv__DeltaTheta_Event__FIELDS, 3, 3},
    },
    {more_interfaces__srv__DeltaTheta_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = more_interfaces__srv__DeltaTheta_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = more_interfaces__srv__DeltaTheta_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x\n"
  "float64 y\n"
  "float64 z\n"
  "---\n"
  "float64 theta1\n"
  "float64 theta2\n"
  "float64 theta3";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
more_interfaces__srv__DeltaTheta__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {more_interfaces__srv__DeltaTheta__TYPE_NAME, 30, 30},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 78, 78},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
more_interfaces__srv__DeltaTheta_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {more_interfaces__srv__DeltaTheta_Request__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
more_interfaces__srv__DeltaTheta_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {more_interfaces__srv__DeltaTheta_Response__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
more_interfaces__srv__DeltaTheta_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {more_interfaces__srv__DeltaTheta_Event__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
more_interfaces__srv__DeltaTheta__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *more_interfaces__srv__DeltaTheta__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *more_interfaces__srv__DeltaTheta_Event__get_individual_type_description_source(NULL);
    sources[3] = *more_interfaces__srv__DeltaTheta_Request__get_individual_type_description_source(NULL);
    sources[4] = *more_interfaces__srv__DeltaTheta_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
more_interfaces__srv__DeltaTheta_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *more_interfaces__srv__DeltaTheta_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
more_interfaces__srv__DeltaTheta_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *more_interfaces__srv__DeltaTheta_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
more_interfaces__srv__DeltaTheta_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *more_interfaces__srv__DeltaTheta_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *more_interfaces__srv__DeltaTheta_Request__get_individual_type_description_source(NULL);
    sources[3] = *more_interfaces__srv__DeltaTheta_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
