#ifndef CLIENT
#define CLIENT

#include "Person.hpp"
using std::string;

class Client: public Person
{
    public:
        Client(string name, string cpf);
};

#endif