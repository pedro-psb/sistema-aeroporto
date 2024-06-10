#ifndef FLIGHTSCHEDULE
#define FLIGHTSCHEDULE 
#include "Flight.hpp" 
class FlightSchedule{
    private:
        Flight* flights;
        int numFlights;
    public:
        FlightSchedule();
        FlightSchedule(Flight* flights, int numFlights);
        Flight* getFlights();
        void setFlights(Flight* flights, int numFlights);
};
#endif