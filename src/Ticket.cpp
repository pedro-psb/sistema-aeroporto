#include "Ticket.hpp"
using std::string;

Ticket::Ticket(
	Passenger* passenger,
 	Flight* flight,
	float price
	// EnumSeat seat, 
	):
	passenger(passenger),
	flight(flight),
	price(price)
	// seat(seat),
{
}

// Ticket::CalculatePrice(EnumSeat seat, float distance)
// {
// 	return 0.0;
// }
