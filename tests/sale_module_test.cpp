#include "../lib/catch.hpp"
#include "../src/SaleModule.hpp"

TEST_CASE("Given a fresh SaleModule", "[functional]") {
  SaleModule saleMod = SaleModule();

  SECTION("When there is a Flight available for Destiny."){};
  SECTION("When there no Flight available for Destiny."){};
  SECTION("When we ask to process a Ticket and the flight has seats."){};
  SECTION("When we ask to process a Ticket and the flight is full."){};
  SECTION("When we ask to cancel a Ticket."){};
}
