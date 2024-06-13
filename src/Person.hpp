#ifndef PERSON
#define PERSON
#include <string>
using std::string;

class Person
{
    protected:
		int id;
        virtual int getId() = 0;

    private:
		static int currentId;
        string name;
        string cpf;

    public:
        Person();
        Person(string name, string cpf);
};
#endif