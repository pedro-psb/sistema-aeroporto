#ifndef CLIENT
#define CLIENT

#include "Person.hpp"
using std::string;

class Client : public Person {
private:
  string passport;

public:
  Client(string name, string cpf, string passport);
  string getPassport();
  int getId() override;
  string getName();
};

#endif