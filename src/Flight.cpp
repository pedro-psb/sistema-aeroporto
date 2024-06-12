
#include "Flight.hpp"
#include <string>
using std::string;

int Flight::currentId = 0;

Flight::Flight(){};

Flight::Flight
	(
		Destination* destination,
		string originPlace,
		DateTime* returnDate, 
		DateTime* exitDate,
		EnumFlight flightType,
		Plane* plane,
		Runway* runway,
		BoardingCrew* crew
	):
	destination(destination),
	originPlace(originPlace),
	returnDate(returnDate), 
	exitDate(exitDate),
	flightType(flightType),
	plane(plane),
	runway(runway),
	crew(crew),
	id(currentId++)
{}

EnumFlight Flight::getFlightType()  {
    return flightType;
}
	

