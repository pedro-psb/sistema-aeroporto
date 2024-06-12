#include "Pilot.hpp"

Pilot::Pilot(string name, string cpf, int license):
    Person(name, cpf), license(license)
{
    
}
    
int Pilot::getId() const {
    return id;
}

