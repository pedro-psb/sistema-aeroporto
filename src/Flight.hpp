#ifndef FLIGHT
#define FLIGHT
#include "EnumFlightStatus.hpp"
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
		EnumFlightStatus status;
		
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
		vector<Ticket*> getTickets();
		EnumFlight getFlightType();
		Destination* getDestination();
		void addTicket(Ticket* ticket);
		void removeTicket(Ticket* ticket);
		void printTickets();
		void printFlight();
		EnumFlightStatus getStatus();
		void setStatus(EnumFlightStatus status);
		int checkCapacity();
		int calculatePrice(EnumSeat seatType);
		Ticket* getTicketByClient(Client* client);
};
#endif

