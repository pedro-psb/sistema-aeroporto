#include "Resource.hpp"
int Resource::currentResourceId = 1;

Resource::Resource() : resource_id(currentResourceId++){};

Resource::Resource(ResourceType resourceType)
    : resource_id(currentResourceId++), resourceType(resourceType){};

int Resource::getResourceId() { return resource_id; }

void Resource::setResourceId(int a) { resource_id = a; }

ResourceType Resource::getType() { return this->resourceType; }
