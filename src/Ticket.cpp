#include "Ticket.hpp"
using std::string;

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

