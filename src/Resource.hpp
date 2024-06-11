#ifndef RESOURCE
#define RESOURCE

enum class ResourceType {
  Plane,
  Pilot,
  Steward,
  Runaway,
};

class Resource {};
class Pilot : public Resource {};
class Plane : public Resource {};
class Steward : public Resource {};
class Runaway : public Resource {};

#endif
