#ifndef PERSON
#define PERSON
#include <string>
using std::string;

class Person
{
    private:
		int id;
        string name;
        string cpf;

    public:
        Person();
        Person(string name, string cpf);
};
#endif