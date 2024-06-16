#include "Steward.hpp"
#include "Resource.hpp"

Steward::Steward() {}

Steward::Steward(string name, string cpf, string gender)
    : Person(name, cpf), gender(gender), Resource(ResourceType::Steward) {}

int Steward::getId() { return id; }

string Steward::getName() { return name; }