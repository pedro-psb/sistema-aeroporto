#include "FlightModule.hpp"
#include "Resource.hpp"
#include "DateTime.hpp"
#include "Ticket.hpp"
#include "Errors.hpp"
#include <string>
#include <iostream>
#include <ctime>

using std::string;
using std::cout;
using std::endl;
using std::vector;

FlightModule::FlightModule(ResourceModule *resourceModule) {
    this->resourceModule = resourceModule;
};

Flight *FlightModule::createFlight(string originPlace, DateTime* departureDate, Destination* destination, EnumFlight flightType) {

    //Create return date based on random numbers, but in less than 5 days
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    DateTime *retuntDate = new DateTime(
        departureDate->getYear(), 
        departureDate->getMonth(), 
        departureDate->getDay() + rand() % 5, 
        departureDate->getHours() + rand() % 23, 
        departureDate->getMinutes() + rand() % 59,
        departureDate->getSeconds() + rand() % 59
        );
    
    //TODO: o bloco abaixo devem ser reescritas quando o módulo de recursos ficar pronto
    Plane *plane = new Plane(500, EnumFlight::COMERCIAL);
    Runway *runway = new Runway("Pista 1");
    Pilot *pilot = new Pilot("João Silva", "12345678", 123456);
    Pilot *copilot = new Pilot("Antonio Rocha", "987654321", 987645);
    Steward *steward = new Steward("Ana Julia", "65498731", "Feminino");
    BoardingCrew *crew = new BoardingCrew(pilot, copilot, steward, 5);

    Flight *flight = new Flight(
        destination,
        originPlace, 
        retuntDate, 
        departureDate, 
        flightType,
        plane, 
        runway,
        crew
    );

    // try {
    //     Resource *plane =
    //         this->resourceModule->getResource(Resource::Plane, dateTime);
    // } catch (...) {
    //     throw CantCreateFlightErrorMsg;
    // };

    return flight;
};

void FlightModule::cancelFlight(Flight flight) { throw 1; };

void FlightModule::addClientToFlight(Client* client, Flight* flight, EnumSeat seatType) { 
    //TODO: Antes de chamar essa fução, verificar se o avião dentro dentes voo ainda tem espaço para mais clientes

    //Calculate ticket price
    EnumFlight flightType = flight->getFlightType();
    Destination* destination = flight->getDestination();
    float distace = destination->getDistance();
    double priceFlightType = getValue(flightType);
    double priceSeatType = getValue(seatType);
    double price = priceFlightType * distace + priceSeatType;

    //Create the ticket and link it to the customer and the flight
    int idFligt = flight->getId();
    Ticket* ticket = new Ticket(client, idFligt, price, seatType);
    flight->addTicket(ticket);
};

void FlightModule::removeClientFromFlight(Client* client, Flight* flight) {
    try
    {
        Ticket* removeTicket;
        for (auto& ticket : flight->getTickets()) {
            if(ticket->getClient()->getId() == client->getId()){
                removeTicket = ticket;
                break;
            }
        }
        flight->removeTicket(removeTicket);
    }
    catch(const std::exception& e)
    {
        throw CANT_REMOVE_CLIENTE;
    }
    

};
