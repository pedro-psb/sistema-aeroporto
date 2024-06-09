#ifndef PLANE
#define PLANE
#include "Resources.hpp"
//#include "EnumPlaneType.hpp"

class Plane: public Resources{
    private:
        int capacity;
        int planeType;
    public:
        int getCapacity();
        int getPlaneType();
        int setCapacity();
        int setPlaneType();

}
#endif