#include "ResourceModule.hpp"
#include "EnumFlight.hpp"
#include "Runway.hpp"
#include "Steward.hpp"

ResourceModule::ResourceModule() {
  this->flightSchedule = FlightSchedule();
  this->resources = {new Plane(10, EnumFlight::COMERCIAL),
                     new Plane(10, EnumFlight::EXECUTIVO),
                     new Plane(10, EnumFlight::CARGA),
                     new Plane(10, EnumFlight::MILITAR)};
  for (int i; i < 4; i++) {
    resources.push_back(new Steward());
    resources.push_back(new Pilot());
  }
};

vector<Resource *> ResourceModule::getAllResources() { return resources; };

vector<Flight *> ResourceModule::getAllFlights() {
  vector<Flight *> _flights = {};
  return _flights;
};

Resource *ResourceModule::getAvailableResource(Resource, DateTime) {
  throw "Calling from ResourceModule";
};
