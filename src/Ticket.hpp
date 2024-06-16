#ifndef TICKET
#define TICKET
#include "Client.hpp"
#include "EnumSeat.hpp"
#include <string>
using std::string;

class Ticket {
private:
  int id;
  Client *client;
  int idFlight;
  float price;
  EnumSeat seatType;

public:
  Ticket(Client *client, int idFlight, float price, EnumSeat seatType);
  EnumSeat getSeatType();
  Client *getClient();
  float getPrice();
  void printTicket();
};
#endif