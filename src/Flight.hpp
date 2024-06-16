#ifndef FLIGHT
#define FLIGHT
#include "BoardingCrew.hpp"
#include "DateTime.hpp"
#include "Destination.hpp"
#include "EnumFlight.hpp"
#include "EnumFlightStatus.hpp"
#include "Plane.hpp"
#include "Runway.hpp"
#include "Ticket.hpp"

#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::vector;

class Flight {
private:
  int id;
  static int currentId;
  Destination *destination;
  string originPlace;
  DateTime *returnDate;
  DateTime *departureDate;
  EnumFlight flightType;
  Plane *plane;
  Runway *runway;
  BoardingCrew *crew;
  vector<Ticket *> tickets;
  EnumFlightStatus status;

public:
  Flight();
  Flight(Destination *destination, string originPlace, DateTime *returnDate,
         DateTime *departureDate, EnumFlight flightType, Plane *plane,
         Runway *runWay, BoardingCrew *crew);
  int getId();
  vector<Ticket *> getTickets();
  EnumFlight getFlightType();
  Destination *getDestination();
  void addTicket(Ticket *ticket);
  void removeTicket(Ticket *ticket);
  void printTickets();
  void printFlight();
  EnumFlightStatus getStatus();
  void setStatus(EnumFlightStatus status);
  int checkCapacity();
  int calculatePrice(EnumSeat seatType);
  Ticket *getTicketByClient(Client *client);
  BoardingCrew *getBoardingCrew();
  Plane *getPlane();
  Runway *getRunway();
  vector<Pilot *> getPilots();
  vector<Steward *> getStewards();
  pair<DateTime, DateTime> getBusyRange();
};
#endif
