#include "FlightModule.hpp"
#include "Resource.hpp"
#include <string>

using std::string;

FlightModule::FlightModule(ResourceModule *resourceModule) {
  this->resourceModule = resourceModule;
};

Flight *FlightModule::createFlight(DateTime dateTime) {
  try {
    Resource *plane =
        this->resourceModule->getResource(ResourceType::Plane, dateTime);
  } catch (...) {
    throw CantCreateFlightErrorMsg;
  };

  return new Flight();
};

void FlightModule::cancelFlight(Flight flight) { throw 1; };

void FlightModule::addClientToFlight(Client client, Flight flight) { throw 1; };

void FlightModule::removeClientFromFlight(Client client, Flight flight) {
  throw 1;
};
