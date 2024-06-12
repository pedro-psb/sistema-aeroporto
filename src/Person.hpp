#ifndef PERSON
#define PERSON
#include <string>
using std::string;

class Person
{
    protected:
		int id;

    private:
		static int currentId;
        string name;
        string cpf;

    public:
        Person();
        Person(string name, string cpf);
};
#endif