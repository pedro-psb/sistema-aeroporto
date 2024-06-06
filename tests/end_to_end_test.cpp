#include "../lib/catch.hpp"
#include "../src/Airport.hpp"

TEST_CASE("Given a fresh Airport") {
  Airport airport = Airport("Meu Aeroporto");

  REQUIRE(airport.getId() == 0);
  REQUIRE(airport.getName() == "Meu Aeroporto");

  // TODO: create cases
}
