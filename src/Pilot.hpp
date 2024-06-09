#ifndef PILOT
#define PILOT
#include "Person.hpp"
using std::string;

class Pilot: public Person
{
    private:
        int license;

    public:
        Pilot(string name, string cpf, int license);

};
#endif