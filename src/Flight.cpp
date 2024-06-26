
#include "Flight.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::string;

int Flight::currentId = 1;

Flight::Flight() : id(currentId++){};

Flight::Flight(Destination *destination, string originPlace,
               DateTime *returnDate, DateTime *departureDate,
               EnumFlight flightType, Plane *plane, Runway *runway,
               BoardingCrew *crew)
    : destination(destination), originPlace(originPlace),
      returnDate(returnDate), departureDate(departureDate),
      flightType(flightType), plane(plane), runway(runway), crew(crew),
      id(currentId++), tickets(), status(EnumFlightStatus::SCHEDULED) {}

int Flight::getId() { return id; }

vector<Ticket *> Flight::getTickets() { return tickets; }

EnumFlight Flight::getFlightType() { return flightType; }

Destination *Flight::getDestination() { return destination; }

void Flight::addTicket(Ticket *ticket) { tickets.push_back(ticket); }

void Flight::removeTicket(Ticket *ticket) {
  auto ticketRemove = std::remove(tickets.begin(), tickets.end(), ticket);
  tickets.erase(ticketRemove, tickets.end());
}

void Flight::printTickets() {
  for (auto &ticket : tickets) {
    ticket->printTicket();
  }
}

void Flight::printFlight() {
  cout << "Flight ID: " << id << endl;
  cout << "Origin: " << originPlace << endl;
  cout << "Destination: " << destination->getName() << endl;
  cout << "Departure Date: " << departureDate->toString() << endl;
  cout << "Return Date: " << returnDate->toString() << endl;
  cout << "Flight Type: " << toString(flightType) << endl;
  cout << "Plane: " << plane->getCapacity() << endl;
  cout << "Pilot: " << crew->getMainPilot()->getName() << endl;
  cout << "Copilot: " << crew->getCopilot()->getName() << endl;
  cout << "Steward 1: " << crew->getStewards()[0]->getName() << endl;
  cout << "Steward 2: " << crew->getStewards()[1]->getName() << endl;
  cout << "Runway: " << runway->getName() << endl;
  cout << "Passengers: " << tickets.size() << endl;
  cout << "Status: " << toString(status) << endl;
  cout << "\n" << endl;
}

EnumFlightStatus Flight::getStatus() { return status; }

void Flight::setStatus(EnumFlightStatus status) { this->status = status; }

int Flight::checkCapacity() {
  int capacity = plane->getCapacity();
  if (capacity > tickets.size()) {
    return 1;
  } else {
    return 0;
  }
}

BoardingCrew *Flight::getBoardingCrew() { return crew; }

Plane *Flight::getPlane() { return plane; }

Runway *Flight::getRunway() { return runway; }

pair<DateTime, DateTime> Flight::getBusyRange() {
  return std::make_pair(*departureDate, *returnDate);
}

int Flight::calculatePrice(EnumSeat seatType) {
  float distace = destination->getDistance();
  double priceFlightType = getValue(flightType);
  double priceSeatType = getValue(seatType);

  return priceFlightType * distace + priceSeatType;
}

Ticket *Flight::getTicketByClient(Client *client) {
  Ticket *ticketReturn;
  for (auto &ticket : tickets) {
    if (ticket->getClient()->getId() == client->getId()) {
      ticketReturn = ticket;
      break;
    }
  }
  return ticketReturn;
}

vector<Pilot *> Flight::getPilots() {
  return {crew->getMainPilot(), crew->getCopilot()};
}

vector<Steward *> Flight::getStewards() { return crew->getStewards(); }