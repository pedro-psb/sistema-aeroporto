#ifndef CLIENT
#define CLIENT

#include "Person.hpp"
using std::string;

class Client: public Person
{
    private:
        int passport;

    public:
        Client(string name, string cpf);
        int getPassport();
};

#endif