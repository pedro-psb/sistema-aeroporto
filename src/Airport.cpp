#include "Airport.hpp"

Airport::Airport(string name) {
  this->id = 0;
  this->name = name;
}

int Airport::getId() { return this->id; }

string Airport::getName() { return this->name; }
