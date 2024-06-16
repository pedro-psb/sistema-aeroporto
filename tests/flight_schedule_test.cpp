#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../src/FlightSchedule.hpp"
#include "../src/Flight.hpp"
#include "../src/FlightModule.hpp"

TEST_CASE("Testando a classe FlightSchedule", "[FlightSchedule]") {
    FlightSchedule schedule=FlightSchedule();
    //Given the information below
    Destination *destination = new Destination("Belo Horizonte", 50);
    DateTime *departureDate = new DateTime(2024, 6, 9, 15, 18, 00);
    ResourceModule* resourceModule = new ResourceModule();
    FlightModule flightModule(resourceModule);

    //When to create the flight
    Flight* flight1 = flightModule.createFlight("Sao Paulo", departureDate, destination, EnumFlight::COMERCIAL);
    Flight* flight2 = flightModule.createFlight("Brasilia", departureDate, destination, EnumFlight::CARGO);
    Flight* flight3 = flightModule.createFlight("Rio de Janeiro", departureDate, destination, EnumFlight::BUSINESS);
    vector<Flight*> flights;
    flights.push_back(flight1);
    flights.push_back(flight2);
    flights.push_back(flight3);

    SECTION("Testando o construtor padrão") {
        REQUIRE(schedule.getFlights().empty());
    }

    SECTION("Testando o construtor com vetor de voos") {
        FlightSchedule scheduleWithFlights(flights);
        REQUIRE(scheduleWithFlights.getFlights().size() == 3);
        REQUIRE(scheduleWithFlights.getFlights() == flights);
    }

    SECTION("Testando a função addFlight com vetor de voos") {
        schedule.addFlight(flights);
        REQUIRE(schedule.getFlights().size() == 3);
        REQUIRE(schedule.getFlights() == flights);
    }

    SECTION("Testando a função addFlight com um voo") {
        schedule.addFlight(flight1);
        REQUIRE(schedule.getFlights().size() == 1);
        REQUIRE(schedule.getFlights()[0] == flight1);
    }

   SECTION("Testando a função removeFlight") {
    schedule.addFlight(flight1);
    schedule.addFlight(flight2);
    schedule.addFlight(flight3);
    REQUIRE(schedule.count() == 3);
    schedule.removeFlight(flight2);
    auto flights = schedule.getFlights();
    auto it = std::find(flights.begin(), flights.end(), flight2);
    REQUIRE(it == flights.end()); 
    it = std::find(flights.begin(), flights.end(), flight1);
    REQUIRE(it != flights.end());
    it = std::find(flights.begin(), flights.end(), flight3);
    REQUIRE(it != flights.end());
    REQUIRE(schedule.count() == 2);
}


    SECTION("Testando a função count") {
        schedule.addFlight(flights);
        REQUIRE(schedule.count() == 3);
    }

    SECTION("Testando a função clearFlights") {
        schedule.addFlight(flights);
        int cleared = schedule.clearFlights();
        REQUIRE(cleared == 3);
        REQUIRE(schedule.getFlights().empty());
    }
}
