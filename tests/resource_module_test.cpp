#include "../lib/catch.hpp"
#include "../src/ResourceModule.hpp"

TEST_CASE("Given a fresh ResourceModule", "[functional]") {
  // initializes wiht 2 unit of each Resource
  ResourceModule *resourceModule = new ResourceModule();

  THEN("It contains some initializer resources and an empty flightSchedule.") {
    vector<Resource *> resources = resourceModule->getAllResources();
    CHECK(resources.size() == 8);

    vector<Flight *> flights = resourceModule->getAllFlights();
    CHECK(flights.size() == 0);
  }

  SECTION("When get a Resource that is available at a DateTime."){
      THEN("We get the request Resource type"){}};

  SECTION("When get a Resource that is not available at a DateTime."){
      THEN("We get an no Resource Available error."){}};

  SECTION("When free a Resource."){THEN("Can get it again"){}};
}
