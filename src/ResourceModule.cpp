#include "ResourceModule.hpp"
#include "EnumFlight.hpp"
#include "Pilot.hpp"
#include "Runway.hpp"
#include "Steward.hpp"

#include <string>
#include <typeinfo>
#include <utility>

ResourceModule::ResourceModule() {}

ResourceModule::ResourceModule(vector<Runway *> runways, vector<Plane *> planes,
                               vector<Pilot *> pilots,
                               vector<Steward *> stewards)
    : runways(runways), pilots(pilots), stewards(stewards), planes(planes),
      flightSchedule(FlightSchedule()) {}

vector<Resource *> ResourceModule::getAllResources() {
  vector<Resource *> resources;
  for (auto plane : planes)
    resources.push_back(plane);
  for (auto steward : stewards)
    resources.push_back(steward);
  for (auto runway : runways)
    resources.push_back(runway);
  for (auto pilot : pilots)
    resources.push_back(pilot);
  return resources;
};

vector<Flight *> ResourceModule::getAllFlights() {
  // TODO: flightSchedule should be modifiable only by this module.
  // Because of that, we should return a copy of the flights, so it can't be
  // modified externally
  return this->flightSchedule.getFlights();
};

void ResourceModule::saveFlight(Flight *flight) {
  this->flightSchedule.addFlight(flight);
};

Flight *ResourceModule::freeFlight(Flight *flight) {
  for (Flight *internalFlight : this->flightSchedule.getFlights()) {
    if (internalFlight->getId() == flight->getId()) {
      this->flightSchedule.removeFlight(flight);
      return internalFlight;
    }
  }
  throw NotInStorageErrorMsg;
};

Plane *ResourceModule::getAvailablePlane(DateTime dateTime) {
  bool taken;
  for (auto plane : planes) {
    // check if this is being used within the requested dateTime
    taken = false;
    for (auto flight : this->flightSchedule.getFlights()) {
      if (flight->getPlane()->getResourceId() == plane->getResourceId()) {
        cout << "found plane " << plane->getResourceId() << " in flight "
             << flight->getId() << endl;
        auto busyRange = flight->getBusyRange();
        if (dateTime > busyRange.first && dateTime < busyRange.second) {
          taken = true;
        }
      }
    }
    if (taken == false)
      return plane;
  };
  throw ResourceNotAvailableErrorMsg;
};

