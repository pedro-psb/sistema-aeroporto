#include "../lib/catch.hpp"
#include "../src/FlightModule.hpp"
#include "../src/ResourceModule.hpp"

#include "mocks/flight_module_mock.cpp"
#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

TEST_CASE("Create Flight") {
    //Given the information below
    Destination *destination = new Destination("Belo Horizonte", 50);
    DateTime *departureDate = new DateTime(2024, 6, 9, 15, 18, 00);
    ResourceModule* resourceModule = new ResourceModule();
    FlightModule flightModule(resourceModule);

    //When to create the flight
    Flight* flight = flightModule.createFlight("Sao Paulo", departureDate, destination, EnumFlight::COMERCIAL);
    
    //Then create a scheduled flight without a ticket
    REQUIRE(flight->getStatus() == EnumFlightStatus::SCHEDULED);
    REQUIRE(flight->getTickets().size() == 0);
}

TEST_CASE("Cancel Flight") {
    //Given the information below
    Destination *destination = new Destination("Belo Horizonte", 50);
    DateTime *departureDate = new DateTime(2024, 6, 9, 15, 18, 00);
    ResourceModule* resourceModule = new ResourceModule();
    FlightModule flightModule(resourceModule);
    Flight* flight = flightModule.createFlight("Sao Paulo", departureDate, destination, EnumFlight::COMERCIAL);

    //When to cancel the flight 
    flightModule.cancelFlight(flight);
    
    //Then the flight status is "cancelled" 
    REQUIRE(flight->getStatus() == EnumFlightStatus::CANCELLED);
}

TEST_CASE("Add Client To Flight") {
    //Given the information below
    Destination *destination = new Destination("Belo Horizonte", 50);
    DateTime *departureDate = new DateTime(2024, 6, 9, 15, 18, 00);
    ResourceModule* resourceModule = new ResourceModule();
    FlightModule flightModule(resourceModule);
    Flight* flight = flightModule.createFlight("Sao Paulo", departureDate, destination, EnumFlight::COMERCIAL);
    Client *client = new Client("Amanda Fiaux", "12365478978", "A753M");

    //When add client to flight
    flightModule.addClientToFlight(client, flight, EnumSeat::ECONOMY_CLASS);
    
    //Then the number of Ticket must be 1
    REQUIRE(flight->getTickets().size() == 1);
}

TEST_CASE("Remove Client From Flight") {
    //Given the information below
    Destination *destination = new Destination("Belo Horizonte", 50);
    DateTime *departureDate = new DateTime(2024, 6, 9, 15, 18, 00);
    ResourceModule* resourceModule = new ResourceModule();
    FlightModule flightModule(resourceModule);
    Flight* flight = flightModule.createFlight("Sao Paulo", departureDate, destination, EnumFlight::COMERCIAL);
    Client *client = new Client("Amanda Fiaux", "12365478978", "A753M");
    flightModule.addClientToFlight(client, flight, EnumSeat::ECONOMY_CLASS);

    //When remove client from flight
    flightModule.removeClientFromFlight(client, flight);
    
    //Then the number of Ticket must be 0
    REQUIRE(flight->getTickets().size() == 0);
}

TEST_CASE("Calculate Ticket Price - Flight COMERCIAL, Seat ECONOMY_CLASS, Distance 50") {
    //Given the information below 
    Destination *destination = new Destination("Belo Horizonte", 50);
    DateTime *departureDate = new DateTime(2024, 6, 9, 15, 18, 00);
    ResourceModule* resourceModule = new ResourceModule();
    FlightModule flightModule(resourceModule);

    //When the flight is COMERCIAL and the seat is ECONOMY_CLASS  
    Flight* flight = flightModule.createFlight("Sao Paulo", departureDate, destination, EnumFlight::COMERCIAL);
    Client *client = new Client("Amanda Fiaux", "12365478978", "A753M");
    flightModule.addClientToFlight(client, flight, EnumSeat::ECONOMY_CLASS);
    Ticket* ticketTest = flight->getTicketByClient(client);
    
    //Then the ticket value must be 2799
    REQUIRE(ticketTest->getPrice() == 2799);
}

TEST_CASE("Calculate Ticket Price - Flight EXECUTIVO, Seat FIRST_CLASS, Distance 50") {
    //Given the information below 
    Destination *destination = new Destination("Belo Horizonte", 50);
    DateTime *departureDate = new DateTime(2024, 6, 9, 15, 18, 00);
    ResourceModule* resourceModule = new ResourceModule();
    FlightModule flightModule(resourceModule);

    //When the flight is EXECUTIVO and the seat is FIRST_CLASS
    Flight* flight = flightModule.createFlight("Sao Paulo", departureDate, destination, EnumFlight::EXECUTIVO);
    Client *client = new Client("Amanda Fiaux", "12365478978", "A753M");
    flightModule.addClientToFlight(client, flight, EnumSeat::FIRST_CLASS);
    Ticket* ticketTest = flight->getTicketByClient(client);
    
    //Then the ticket value must be 4615
    REQUIRE(ticketTest->getPrice() == 4615);
}