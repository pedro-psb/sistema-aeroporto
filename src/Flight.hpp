#ifndef FLIGHT
#define FLIGHT
#include "Ticket.hpp"
#include "DateTime.hpp"
#include "EnumFlight.hpp" 
#include "Destination.hpp"
#include "Plane.hpp"
#include "Runway.hpp"
#include "BoardingCrew.hpp"
#include <vector>

using std::string;
using std::vector;

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
		vector<Ticket*> tickets;
		
    public:
		Flight();
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
		int getId();
		EnumFlight getFlightType();
		Destination* getDestination();
		void addTicket(Ticket* ticket);
		void removeTicket(Ticket* ticket);
};
#endif
