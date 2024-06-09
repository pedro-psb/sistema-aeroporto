#ifndef FLIGHTSCHEDULE
#define FLIGHTSCHEDULE 
#include "Flight.hpp" 
class FlightSchedule{
    private:
        Flight* flights;
    public:
        FlightSchedule();
        FlightSchedule(Flight flights[]);
        Flight* getFlights();
        void setFlights(Flight flights[]);
};
#endif