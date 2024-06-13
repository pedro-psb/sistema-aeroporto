#include <string>
#include "Destination.hpp"
using std::string;

int Destination::currentId = 0;

Destination::Destination(string name, double distance)
    :name(name), distance(distance),id(currentId++) 
{}
	
int Destination::getId(){
    return id;
}

double Destination::getDistance() {
    return distance;
}

