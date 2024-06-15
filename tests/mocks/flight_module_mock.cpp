#include "flight_module_mock.hpp"
#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

ResourceModuleMock::ResourceModuleMock() {
  // bool getResourceRaise = false;
  // int pilotId = 0;
  // int stewardId = 0;
  // int PlaneId = 0;
  // int RunawayId = 0;
  // mockResourceMap = {
  //     {Pilot::Pilot, {new Pilot()}},
  //     {Plane::Plane, {new Plane(), new Plane()}},
  //     {Steward::Steward, {new Steward(), new Steward}},
  //     {Runway::Runway, {new Runway(), new Runway()}},
  // };
  // getResourceRaise = false;
}

Resource *ResourceModuleMock::getResource(Resource resource,
                                          DateTime dateTime) {
  // cout << "Mock getResource being called" << endl;
  // if (this->getResourceRaise == true) {
  //   throw CantCreateResourceErrorMsg;
  // }
  // return this->mockResourceMap[resource][0];
};
