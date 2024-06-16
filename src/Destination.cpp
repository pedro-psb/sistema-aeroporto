#include "Destination.hpp"
#include <string>
using std::string;

int Destination::currentId = 1;

Destination::Destination(string name, double distance)
    : name(name), distance(distance), id(currentId++) {}

int Destination::getId() { return id; }

double Destination::getDistance() { return distance; }

string Destination::getName() { return name; }
