
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
		Plane* plane,
		Runway* runway,
		BoardingCrew* crew,
		EnumFlight flightType
	):
	destination(destination),
	originPlace(originPlace),
	returnDate(returnDate), 
	exitDate(exitDate),
	plane(plane),
	runway(runway),
	crew(crew),
	flightType(flightType)
{}

EnumFlight Flight::getFlightType()  {
    return flightType;
}
	

