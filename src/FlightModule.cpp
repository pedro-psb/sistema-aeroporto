#include "FlightModule.hpp"
#include "DateTime.hpp"
#include "Errors.hpp"
#include "Resource.hpp"
#include "Ticket.hpp"
#include <ctime>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

FlightModule::FlightModule(ResourceModule *resourceModule) {
  this->resourceModule = resourceModule;
};

Flight *FlightModule::createFlight(string originPlace, DateTime *departureDate,
                                   Destination *destination,
                                   EnumFlight flightType) {

  DateTime departureDateresource =
      DateTime(departureDate->getYear(), departureDate->getMonth(),
               departureDate->getDay(), departureDate->getHours(),
               departureDate->getMinutes(), departureDate->getSeconds());

  // Create return date based on random numbers, but in less than 5 days
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  DateTime *retuntDate =
      new DateTime(departureDate->getYear(), departureDate->getMonth(),
                   departureDate->getDay() + rand() % 5,
                   departureDate->getHours() + rand() % 23,
                   departureDate->getMinutes() + rand() % 59,
                   departureDate->getSeconds() + rand() % 59);

  try {
    Plane *plane = resourceModule->getAvailablePlane(departureDateresource);
    vector<Pilot *> pilots =
        resourceModule->getAvailablePilot(departureDateresource);
    Runway *runway = resourceModule->getAvailableRunway(departureDateresource);
    vector<Steward *> stewards =
        resourceModule->getAvailableSteward(departureDateresource);

    if (pilots.size() < 2) {
      throw "----- Insufficient number of pilots for the flight! -----";
    }

    if (stewards.size() < 2) {
      throw "----- Insufficient number of stewards for the flight! -----";
    }

    BoardingCrew *crew =
        new BoardingCrew(pilots[0], pilots[1], {stewards[0], stewards[1]});

    Flight *flight = new Flight(destination, originPlace, retuntDate,
                                departureDate, flightType, plane, runway, crew);

    return flight;
  } catch (const char *msg) {
    std::cerr << "Erro: " << msg << std::endl;
    throw "Failed to create flight:";
  }
};

void FlightModule::cancelFlight(Flight *flight) {
  flight->setStatus(EnumFlightStatus::CANCELLED);

  for (auto &ticket : flight->getTickets()) {
    removeClientFromFlight(ticket->getClient(), flight);
  }

  cout << "----- Flight successfully cancelled! ----- \n" << endl;
};

void FlightModule::addClientToFlight(Client *client, Flight *flight,
                                     EnumSeat seatType) {

  if (flight->checkCapacity()) {
    // Calculate ticket price
    double price = flight->calculatePrice(seatType);

    // Create the ticket and link it to the customer and the flight
    int idFligt = flight->getId();
    Ticket *ticket = new Ticket(client, idFligt, price, seatType);
    flight->addTicket(ticket);
    cout << "----- Client successfully entered the flight! -----" << endl;
  } else {
    throw "----- It was not possible to add a client to the flight. Full "
          "flight. -----";
  }
};

void FlightModule::removeClientFromFlight(Client *client, Flight *flight) {

  Ticket *removeTicket;
  for (auto &ticket : flight->getTickets()) {
    if (ticket->getClient()->getId() == client->getId()) {
      removeTicket = ticket;
      break;
    }
  }
  flight->removeTicket(removeTicket);
  cout << "----- Client successfully removed from flight! -----" << endl;
};