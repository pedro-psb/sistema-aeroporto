#include "Client.hpp"

Client::Client(string name, string cpf, string passport):
    Person(name, cpf), passport(passport){}

string Client::getPassport(){
    return passport;
}

int Client::getId(){
    return id;
}

string Client::getName(){
    return name;
}


    
