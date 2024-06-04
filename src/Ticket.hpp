#ifndef TICKET
#define TICKET
#include <string>
#include "Passenger.hpp"
#include "Flight.hpp"
using std::string;

class Ticket
{
	private:
		int id;
		Passenger* passenger;
		Flight* flight;
		float price;
		// EnumSeat: seat;
		
    public:
        Ticket(
			Passenger* passenger, 
			Flight* flight, 
			float price
			// EnumSeat serat, 
		);
        // float CalculatePrice(EnumSeat seat, float distance);
};
#endif