
#include "Flight.hpp"
#include <string>
using std::string;

Flight::Flight
	(
		Destination* destination,
		string originPlace,
		DateTime* returnDate, 
		DateTime* exitDate 
		// EnumFlight flight,
		// AirPlane airPlane, 
		// RunWay runWay, 
		// AirCrew airCrew
	):
	destination(destination),
	originPlace(originPlace),
	returnDate(returnDate), 
	exitDate(exitDate)
	// flight (flight),
	// airPlane (airPlane), 
	// runWay (runWay), 
	// airCrew (airCrew)
{}
	

