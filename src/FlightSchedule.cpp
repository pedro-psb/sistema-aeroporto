#include "FlightSchedule.hpp"
FlightSchedule::FlightSchedule(){

}
FlightSchedule::FlightSchedule(Flight* flights):flights(flights){

}
Flight* FlightSchedule::getFlights(){
    return flights;
}
void FlightSchedule::setFlights(Flight* sch){
    flights=sch;
}