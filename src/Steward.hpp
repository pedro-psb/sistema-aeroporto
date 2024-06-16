#ifndef STEWARD
#define STEWARD
#include "Person.hpp"
#include "Resource.hpp"
using std::string;

class Steward: public Person, public Resource
{
    private:
        string gender;

    public:
        Steward();
        Steward(string name, string cpf, string gender);
        int getId() override;
        string getName();
};
#endif
