#include "Plane.cpp"
Plane::Plane(){

}
Plane::Plane(int capacity, int planeType, int id):Resources(id), capacity(capacity),planeType(planeType){

}
int Plane::getCapacity(){
    return capacity;
}
void Plane::setCapacity(int cap){
    capacity=cap;
}
int Plane::getPlaneType(){
    return PlaneType;
}
int Plane::setPlaneType(int pt){
    planeType=pt;
}