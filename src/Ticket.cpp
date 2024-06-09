#include "Ticket.hpp"
using std::string;

Ticket::Ticket(
	Client* client,
 	Flight* flight,
	float price,
	EnumSeat seatType
	):
	client(client),
	flight(flight),
	price(price),
	seatType(seatType)
{
}

EnumSeat Ticket::getSeatType()  {
    return seatType;
}

// Ticket::CalculatePrice(EnumSeat seat, float distance)
// {
// 	return 0.0;
// }
