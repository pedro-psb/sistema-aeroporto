#include "Resources.hpp"
Resources::Resources(){};

Resources::Resources(int id):id(id){};

int Resources::getId(){
    return id;
}

void Resources::setId(int a){
    id=a;
}