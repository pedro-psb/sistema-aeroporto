#ifndef FLIGHT
#define FLIGHT
#include "DateTime.hpp"
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
		// EnumFlight: flight;
		// AirPlane airPlane:
		// RunWay runWay;
		// AirCrew airCrew;
		
    public:
        Flight
        (
			Destination* destination,
			string OriginPlace,
			DateTime* returnDate, 
			DateTime* exitDate 
			// EnumFlight flight,
			// AirPlane airPlane, 
			// RunWay runWay, 
			// AirCrew airCrew
		);
};
#endif