#include "../lib/catch.hpp"
#include "../src/FlightModule.hpp"
#include "../src/ResourceModule.hpp"

#include "mocks/flight_module_mock.cpp"
#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

TEST_CASE("Given a fresh Mock ResourceModule", "[functional]") {
  ResourceModuleMock *resourceModuleMock = new ResourceModuleMock();
  auto pilot = resourceModuleMock->getResource(ResourceType::Pilot, DateTime());

  SECTION("When enabling the mock raise-flag") {
    resourceModuleMock->getResourceRaise = true;

    THEN("An throw is thrown error") {
      REQUIRE_THROWS_WITH(
          resourceModuleMock->getResource(ResourceType::Pilot, DateTime()),
          CantCreateResourceErrorMsg);
    }
  }
}

TEST_CASE("Given a fresh FlightModule", "[functional]") {
  ResourceModuleMock *resourceModuleMock = new ResourceModuleMock();
  FlightModule *flightMod = new FlightModule(resourceModuleMock);
  DateTime someTime = DateTime();

  SECTION("When we create a fresh Flight and there are enough resources.") {
    Flight *newFlight = flightMod->createFlight(someTime);

    THEN("A new Flight is created") {
      REQUIRE(newFlight != nullptr);
      // REQUIRE(newFlight->departureTime == someTime);
    }
  }

  SECTION("When we create a fresh Flight and there are not enough resources.") {
    resourceModuleMock->getResourceRaise = true;

    THEN("Throw error saying that cannot create flight.") {
      REQUIRE_THROWS_WITH(flightMod->createFlight(someTime),
                          CantCreateFlightErrorMsg);
    }
  }

  SECTION("When we add a Client to a Flight and the flight has seats."){};
  SECTION("When we add a Client to a Flight and the flight is full."){};
  SECTION("When we remove a Client from a Flight."){};
  SECTION("When we cancel a Flight."){};
}
