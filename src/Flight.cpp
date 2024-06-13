
#include "Flight.hpp"
#include <string>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int Flight::currentId = 1;

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
	tickets(),
	status(EnumFlightStatus::SCHEDULED)
{}

int Flight::getId(){
	return id;
}

vector<Ticket*> Flight::getTickets(){
	return tickets;
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

void Flight::printTickets(){
	for (auto& ticket : tickets) {
		ticket->printTicket();
	}
}

void Flight::printFlight(){
	cout << "Flight ID: " << id << endl;
	cout << "Origin: " << originPlace << endl;
	cout << "Destination: " << destination->getName() << endl;
	cout << "Departure Date: " << departureDate->toString() << endl;
	cout << "Return Date: " << returnDate->toString() << endl;
	cout << "Flight Type: " << toString(flightType) << endl;
	cout << "Passengers: " << tickets.size() << endl;
	cout << "Status: " <<  toString(status) << endl;
	cout << "\n"<< endl;
}

void Flight::setStatus(EnumFlightStatus status){
	this->status = status;
}

int Flight::checkCapacity(){
	int capacity = plane->getCapacity();
	if(capacity > tickets.size()){
		return 1;
	}else{
		return 0;
	}
}
