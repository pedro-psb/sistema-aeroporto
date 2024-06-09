#include "ResourceModule.hpp"

ResourceModule::ResourceModule(){};
Resource *ResourceModule::getResource(ResourceType, DateTime) { throw "Calling from ResourceModule"; };
