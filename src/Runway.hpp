#ifndef RUNWAY
#define RUNWAY 
#include "Resources.hpp"
#include <string>
using std::string;

class Runway: public Resources{
    private:
        string name;
    public:
        Runway();
        Runway(string name, int id);
        string getName();
        void setName(string name);

};
#endif