#include "Person.hpp"

int Person::currentId = 1;

Person::Person() {}

Person::Person(string name, string cpf)
    : name(name), cpf(cpf), id(currentId++) {}
