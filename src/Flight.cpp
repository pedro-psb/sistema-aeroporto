
#include "Flight.hpp"
#include <string>
using std::string;

Flight::Flight(){};

Flight::Flight
	(
		Destination* destination,
		string originPlace,
		DateTime* returnDate, 
		DateTime* exitDate,
		EnumFlight flightType
		// AirPlane airPlane, 
		// RunWay runWay, 
		// AirCrew airCrew
	):
	destination(destination),
	originPlace(originPlace),
	returnDate(returnDate), 
	exitDate(exitDate),
	flightType(flightType)
	// airPlane (airPlane)
	// runWay (runWay)
	// airCrew (airCrew)
{}

EnumFlight Flight::getFlightType()  {
    return flightType;
}
	

