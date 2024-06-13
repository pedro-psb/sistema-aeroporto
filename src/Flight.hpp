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
		static int currentId;
		Destination* destination;
		string originPlace;
		DateTime* returnDate;
		DateTime* departureDate;
		EnumFlight flightType;
		Plane* plane;
		Runway* runway;
		BoardingCrew* crew;
		
    public:
        Flight
        (
			Destination* destination,
			string originPlace,
			DateTime* returnDate, 
			DateTime* departureDate,
			EnumFlight flightType,
			Plane* plane,
			Runway* runWay,
			BoardingCrew* crew
		);
		Flight();
		EnumFlight getFlightType();
		Destination* getDestiantion();

};
#endif
