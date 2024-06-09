#ifndef TICKET
#define TICKET
#include <string>
#include "Client.hpp"
#include "Flight.hpp"
#include "Enum/EnumSeat.cpp" 
using std::string;

class Ticket
{
	private:
		int id;
		Client* client;
		Flight* flight;
		float price;
		EnumSeat seatType;
		
    public:
        Ticket(
			Client* client, 
			Flight* flight, 
			float price,
			EnumSeat seatType
		);
        // float CalculatePrice(EnumSeat seat, float distance);
};
#endif