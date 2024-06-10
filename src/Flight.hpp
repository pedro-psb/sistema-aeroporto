#ifndef FLIGHT
#define FLIGHT
#include "DateTime.hpp"
#include "EnumFlight.hpp" 
#include "Destination.hpp"
using std::string;

class Flight
{
	private:
		int id;
		Destination* destination;
		string originPlace;
		DateTime* returnDate;
		DateTime* exitDate;
		EnumFlight flightType;
		// AirPlane airPlane:
		// RunWay runWay;
		// AirCrew airCrew;
		
    public:
        Flight
        (
			Destination* destination,
			string OriginPlace,
			DateTime* returnDate, 
			DateTime* exitDate,
			EnumFlight flightType
			// AirPlane airPlane
			// RunWay runWay
			// AirCrew airCrew
		);
		Flight();
		EnumFlight getFlightType();
};
#endif