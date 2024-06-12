#include "Resource.hpp"
int Resource::currentId = 0;

Resource::Resource()
    :id(currentId++)
{};

int Resource::getId(){
    return id;
}

void Resource::setId(int a){
    id=a;
}