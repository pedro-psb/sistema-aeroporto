#include "Airport.hpp"

int Airport::currentId = 1;

Airport::Airport(string name) {
  this->id = currentId++;
  this->name = name;
}

int Airport::getId() { return this->id; }

string Airport::getName() { return this->name; }
