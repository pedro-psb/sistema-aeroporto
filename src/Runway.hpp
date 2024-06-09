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
        Runaway(string name);
        string getName();
        void setName(string name);

}
#endif