#include "ResourceModule.hpp"

ResourceModule::ResourceModule(){};
Resource *ResourceModule::getResource(Resource, DateTime) { throw "Calling from ResourceModule"; };
