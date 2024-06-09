#ifndef RUNWAY
#define RUNWAY 
#include "Resources.hpp"
#include <string>
using std::string;
class Runway: public Resources{
    private:
        string name;
    public:
        string getName();
        void setName(string name);

}
#endif