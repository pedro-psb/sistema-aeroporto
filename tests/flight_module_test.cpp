#include "../lib/catch.hpp"
#include "../src/FlightModule.hpp"

TEST_CASE("Given a fresh FlightModule") {
  FlightModule flightMod = FlightModule();

  SECTION("When we add a Client to a Flight and the flight has seats."){};
  SECTION("When we add a Client to a Flight and the flight is full."){};
  SECTION("When we remove a Client from a Flight."){};
  SECTION("When we create a fresh Flight and there are enough resources."){};
  SECTION("When we create a fresh Flight and there are not enough resources."){};
  SECTION("When we cancel a Flight."){};
}
