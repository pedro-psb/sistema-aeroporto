#include "Ticket.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

Ticket::Ticket(
	Client* client,
 	int idFlight,
	float price,
	EnumSeat seatType
	):
	client(client),
	idFlight(idFlight),
	price(price),
	seatType(seatType)
{
}

EnumSeat Ticket::getSeatType()  {
    return seatType;
}

Client* Ticket::getClient()  {
    return client;
}

void Ticket::printTicket(){
	cout << "Client ID: " << client->getId() << endl;
	cout << "Client Passport: " << client->getPassport() << endl;
	cout << "Client Name: " << client->getName() << endl;
	cout << "Seat: " << toString(seatType) << endl;
	cout << "Price: " << price << endl;
	cout << "\n"<< endl;
}

