#include "Client.hpp"

Client::Client(string name, string cpf):
    Person(name, cpf)
{}

int Client:: getPassport()
{
    return passport;
}

    
