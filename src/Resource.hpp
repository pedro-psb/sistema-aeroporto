#ifndef RESOURCE
#define RESOURCE

#include <string>
using std::string;

enum class ResourceType { Runway, Steward, Pilot, Plane };

class Resource {
protected:
  int resource_id;
  ResourceType resourceType;

private:
  static int currentResourceId;

public:
  Resource();
  Resource(ResourceType resourceType);
  ResourceType getType();
  int getResourceId();
  void setResourceId(int id);
};
#endif
