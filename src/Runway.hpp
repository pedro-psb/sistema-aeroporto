#ifndef RUNWAY
#define RUNWAY 
#include "Resource.hpp"
#include <string>
using std::string;

class Runway: public Resource{
    private:
        string name;
        
    public:
        Runway();
        Runway(string name);
        string getName();
        void setName(string name);

};
#endif