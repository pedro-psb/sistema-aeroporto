#include "Pilot.hpp"
#include "Resource.hpp"

Pilot::Pilot(string name, string cpf, int license):
    Person(name, cpf), license(license), Resource(ResourceType::Pilot){}
    
int Pilot::getId() {
    return id;
}

string Pilot::getName() {
    return name;
}

