#ifndef STEWARD
#define STEWARD
#include "Person.hpp"
using std::string;

class Steward: public Person
{
    private:
        string gender;

    public:
        Steward(string name, string cpf, string gender);

};
#endif