#ifndef PERSON
#define PERSON
#include <string>
using std::string;

class Person
{
    protected:
		int id;
        string name;
        string cpf;
        virtual int getId() = 0;

    private:
		static int currentId;

    public:
        Person();
        Person(string name, string cpf);
};
#endif