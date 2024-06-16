#ifndef PILOT
#define PILOT
#include "Person.hpp"
#include "Resource.hpp"
using std::string;

class Pilot: public Person, public Resource
{
    private:
        int license;

    public:
        Pilot();
        Pilot(string name, string cpf, int license);
        int getId() override;
        string getName();

};
#endif
