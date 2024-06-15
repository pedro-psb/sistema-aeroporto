#include "Resource.hpp"
int Resource::currentResourceId = 1;

Resource::Resource()
    :resource_id(currentResourceId++)
{};

int Resource::getResourceId(){
    return resource_id;
}

void Resource::setResourceId(int a){
    resource_id=a;
}
