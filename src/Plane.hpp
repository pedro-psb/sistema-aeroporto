#ifndef PLANE
#define PLANE
#include "EnumFlight.hpp"
#include "Resource.hpp"

class Plane : public Resource {
private:
  int capacity;
  EnumFlight planeType;

public:
  Plane(int capacity, EnumFlight planeType);
  int getCapacity();
  EnumFlight getPlaneType();
  void setCapacity(int capacity);
  void setPlaneType(EnumFlight planeType);
};
#endif
