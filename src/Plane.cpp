#include "Plane.hpp"
#include "Resource.hpp"

Plane::Plane(int capacity, EnumFlight planeType)
    : capacity(capacity), planeType(planeType), Resource(ResourceType::Plane) {}

int Plane::getCapacity() { return capacity; }

void Plane::setCapacity(int cap) { capacity = cap; }

EnumFlight Plane::getPlaneType() { return planeType; }

void Plane::setPlaneType(EnumFlight pt) { planeType = pt; }
