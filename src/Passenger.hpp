#ifndef PASSENGER
#define PASSENGER

#include "Person.hpp"
using std::string;

class Passenger: public Person
{
    public:
        Passenger(string name, string cpf);
};

#endif