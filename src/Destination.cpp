#include <string>
#include "Destination.hpp"
using std::string;

int Destination::currentId = 0;

Destination::Destination(string name, float distance)
    :name(name), distance(distance),id(currentId++) 
{}
	
int Destination::getId() const {
    return id;
}

