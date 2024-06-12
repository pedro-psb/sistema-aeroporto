#include "Plane.hpp"
Plane::Plane(){

}
Plane::Plane(int capacity, EnumFlight planeType, int id)
    :capacity(capacity), planeType(planeType), Resource(id){
}

int Plane::getCapacity(){
    return capacity;
}

void Plane::setCapacity(int cap){
    capacity=cap;
}

EnumFlight Plane::getPlaneType(){
    return planeType;
}

void Plane::setPlaneType(EnumFlight pt){
    planeType=pt;
}