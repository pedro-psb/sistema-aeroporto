#ifndef TICKET
#define TICKET
#include <string>
#include "Client.hpp"
#include "EnumSeat.hpp" 
using std::string;

class Ticket
{
	private:
		int id;
		Client* client;
		int idFlight;
		float price;
		EnumSeat seatType;
		
    public:
        Ticket(
			Client* client, 
			int idFlight, 
			float price,
			EnumSeat seatType
		);
		EnumSeat getSeatType();
		Client* getClient();
		void printTicket();
};
#endif