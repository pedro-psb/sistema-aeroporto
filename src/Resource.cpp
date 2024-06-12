#include "Resource.hpp"
Resource::Resource(){};

Resource::Resource(int id):id(id){};

int Resource::getId(){
    return id;
}

void Resource::setId(int a){
    id=a;
}