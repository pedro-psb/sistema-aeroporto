#ifndef PLANE
#define PLANE
#include "Resources.hpp"
#include "EnumFlight.hpp" 

class Plane: public Resources{
    private:
        int capacity;
        EnumFlight planeType;
    public:
        Plane();
        Plane(int capacity, EnumFlight planeType, int id);
        int getCapacity();
        EnumFlight getPlaneType();
        void setCapacity(int capacity);
        void setPlaneType(EnumFlight planeType);

};
#endif