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

bool ResourceModule::isDateInRange(DateTime date,
                                   pair<DateTime, DateTime> dateRange) {
  return (date > dateRange.first && date < dateRange.second);
};

Plane *ResourceModule::getAvailablePlane(DateTime dateTime) {
  bool taken;
  for (auto plane : planes) {
    taken = false;
    for (auto flight : this->flightSchedule.getFlights()) {
      if (flight->getPlane()->getResourceId() == plane->getResourceId())
        taken = isDateInRange(dateTime, flight->getBusyRange());
    }
    if (taken == false)
      return plane;
  };
  throw ResourceNotAvailableErrorMsg;
};

vector<Pilot *> ResourceModule::getAvailablePilot(DateTime dateTime) {
  bool taken;
  vector<Pilot *> vectorPilots = {};

  for (auto pilot : pilots) {
    taken = false;
    for (auto flight : this->flightSchedule.getFlights()) {
      for (auto flightPilot : flight->getPilots()) {
        if (pilot->getResourceId() == flightPilot->getResourceId())
          taken = isDateInRange(dateTime, flight->getBusyRange());
      }
    }
    if (taken == false)
      vectorPilots.push_back(pilot);
  };

  if (vectorPilots.size() == 0)
    throw ResourceNotAvailableErrorMsg;

  return vectorPilots;
};

vector<Steward *> ResourceModule::getAvailableSteward(DateTime dateTime) {
  bool taken;
  vector<Steward *> vectorStewards = {};

  for (auto thisSteward : stewards) {
    taken = false;
    for (auto flight : this->flightSchedule.getFlights()) {
      for (auto flightSteward : flight->getStewards()) {
        if (thisSteward->getResourceId() == flightSteward->getResourceId())
          taken = isDateInRange(dateTime, flight->getBusyRange());
      }
    }
    if (taken == false)
      vectorStewards.push_back(thisSteward);
  };

  if (vectorStewards.size() == 0)
    throw ResourceNotAvailableErrorMsg;

  return vectorStewards;
};

Runway *ResourceModule::getAvailableRunway(DateTime dateTime) {
  bool taken;
  for (auto runway : runways) {
    taken = false;
    for (auto flight : this->flightSchedule.getFlights()) {
      if (runway->getResourceId() == flight->getRunway()->getResourceId())
        taken = isDateInRange(dateTime, flight->getBusyRange());
    }
    if (taken == false)
      return runway;
  };
  throw ResourceNotAvailableErrorMsg;
};
