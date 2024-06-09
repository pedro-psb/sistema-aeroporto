#include "Plane.hpp"
Plane::Plane(){

}
Plane::Plane(int capacity, int planeType, int id):capacity(capacity),planeType(planeType),Resources(id){

}
int Plane::getCapacity(){
    return capacity;
}
void Plane::setCapacity(int cap){
    capacity=cap;
}
int Plane::getPlaneType(){
    return planeType;
}
void Plane::setPlaneType(int pt){
    planeType=pt;
}