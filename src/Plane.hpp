#ifndef PLANE
#define PLANE
#include "Resources.hpp"
//#include "EnumPlaneType.hpp"

class Plane: public Resources{
    private:
        int capacity;
        int planeType;
    public:
        Plane();
        Plane(int capacity, int planeType, int id);
        int getCapacity();
        int getPlaneType();
        void setCapacity(int capacity);
        void setPlaneType(int planeType);

};
#endif