#include "../../src/ResourceModule.hpp"
#include <iostream>
#include <map>
#include <string>

using std::vector, std::string, std::cout, std::endl;

// Mocks
class ResourceModuleMock : public ResourceModule {
public:
  // std::map<Resource, vector<Resource *>> mockResourceMap;
  bool getResourceRaise;
  int pilotId;
  int stewardId;
  int PlaneId;
  int RunawayId;

  /* Recursos falsos.
   * Mas talvez possamos realmente usar um mapa para definir os recursos em
   * ResourceModule */
  ResourceModuleMock();

  /* Return generated Resources with additive id's */
  Resource *getAvailableResource(Resource resource, DateTime dateTime);
};
