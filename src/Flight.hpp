#ifndef FLIGHT
#define FLIGHT
#include "DateTime.hpp"
#include "EnumFlight.hpp" 
#include "Destination.hpp"
#include "Plane.hpp"
#include "Runway.hpp"
#include "BoardingCrew.hpp"
using std::string;

class Flight
{
	private:
		int id;
		Destination* destination;
		string originPlace;
		DateTime* returnDate;
		DateTime* exitDate;
		Plane* plane;
		Runway* runway;
		BoardingCrew* crew;
		EnumFlight flightType;
		
    public:
        Flight
        (
			Destination* destination,
			string originPlace,
			DateTime* returnDate, 
			DateTime* exitDate,
			Plane* plane,
			Runway* runWay,
			BoardingCrew* crew,
			EnumFlight flightType
		);
		Flight();
		EnumFlight getFlightType();
};
#endif
