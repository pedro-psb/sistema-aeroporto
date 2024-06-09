#include "flight_module_mock.hpp"
#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

ResourceModuleMock::ResourceModuleMock() {
  bool getResourceRaise = false;
  int pilotId = 0;
  int stewardId = 0;
  int PlaneId = 0;
  int RunawayId = 0;
  mockResourceMap = {
      {ResourceType::Pilot, {new Pilot()}},
      {ResourceType::Plane, {new Plane(), new Plane()}},
      {ResourceType::Steward, {new Steward(), new Steward}},
      {ResourceType::Runaway, {new Runaway(), new Runaway()}},
  };
  getResourceRaise = false;
}

Resource *ResourceModuleMock::getResource(ResourceType resourceType,
                                          DateTime dateTime) {
  cout << "Mock getResource being called" << endl;
  if (this->getResourceRaise == true) {
    throw CantCreateResourceErrorMsg;
  }
  return this->mockResourceMap[resourceType][0];
};
