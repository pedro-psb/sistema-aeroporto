
#include "Flight.hpp"
#include "Errors.hpp"
#include <string>
#include <algorithm>
using std::string;

int Flight::currentId = 0;

Flight::Flight(){};

Flight::Flight
	(
		Destination* destination,
		string originPlace,
		DateTime* returnDate, 
		DateTime* departureDate,
		EnumFlight flightType,
		Plane* plane,
		Runway* runway,
		BoardingCrew* crew
	):
	destination(destination),
	originPlace(originPlace),
	returnDate(returnDate), 
	departureDate(departureDate),
	flightType(flightType),
	plane(plane),
	runway(runway),
	crew(crew),
	id(currentId++),
	tickets()
{}

int Flight::getId(){
	return id;
}

EnumFlight Flight::getFlightType()  {
    return flightType;
}

Destination* Flight::getDestination()  {
    return destination;
}

void Flight::addTicket(Ticket* ticket){
	tickets.push_back(ticket);
}

void Flight::removeTicket(Ticket* ticket){
	auto  ticketRemove = std::remove(tickets.begin(), tickets.end(), ticket);
	tickets.erase(ticketRemove, tickets.end());
}
	

