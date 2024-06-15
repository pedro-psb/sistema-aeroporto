#include "../lib/catch.hpp"
#include "../src/ResourceModule.hpp"

TEST_CASE("Given a fresh ResourceModule with 8 resources", "[functional]") {
  vector<Plane *> planes{new Plane(10, EnumFlight::COMERCIAL),
                         new Plane(10, EnumFlight::BUSINESS),
                         new Plane(10, EnumFlight::CARGO),
                         new Plane(10, EnumFlight::MILITARY)};
  vector<Pilot *> pilots{new Pilot("fulano", "111.111.111-11", 100)};
  vector<Steward *> stewards{new Steward("fulana", "222.222.222-22", "woman")};
  vector<Runway *> runways{new Runway("foo"), new Runway("bar")};
  ResourceModule resourceModule =
      ResourceModule(runways, planes, pilots, stewards);

  THEN("It contains some initializer resources and an empty flightSchedule.") {
    vector<Resource *> resources = resourceModule.getAllResources();
    CHECK(resources.size() == 8);

    vector<Flight *> flights = resourceModule.getAllFlights();
    CHECK(flights.size() == 0);
  }

  SECTION("When a Flight is saved.") {
    Flight *flightA = new Flight();
    Flight *flightB = new Flight();
    CHECK(flightA->getId() != flightB->getId());
    resourceModule.saveFlight(flightA);
    THEN("It is persistent in the internal storage") {
      REQUIRE(resourceModule.getAllFlights().size() == 1);
    }

    SECTION("And when a Flight is removed and exists in the storage.") {
      Flight *removedFlight = resourceModule.freeFlight(flightA);
      THEN("Its deleted from storage, but the object is not deleted.") {
        REQUIRE(resourceModule.getAllFlights().size() == 0);
        REQUIRE(removedFlight->getId() == flightA->getId());
      }
    }

    SECTION("And when a Flight is removed but its not in the storage.") {
      THEN("An error is thrown") {
        REQUIRE_THROWS_WITH(resourceModule.freeFlight(flightB),
                            NotInStorageErrorMsg);
      }
    }
  };
}

TEST_CASE("Given a fresh ResourceModule with 1 available resource of each type",
          "[functional]") {
  Plane *planeA = new Plane(10, EnumFlight::COMERCIAL);
  Pilot *pilotA = new Pilot("foo", "bar", 123);
  Steward *stewardA = new Steward("foo", "bar", "eggs");
  Runway *runwayA = new Runway("runway");
  ResourceModule resourceModule =
      ResourceModule({runwayA}, {planeA}, {pilotA}, {stewardA});

  // TODO: do the same for the rest of Resources
  SECTION("When try to get a Plane for a DateTime and one available.") {
    CHECK(resourceModule.getAllFlights().size() == 0);
    DateTime someTime = DateTime(2000, 1, 1, 1, 00, 00);
    Plane *somePlane = resourceModule.getAvailablePlane(someTime);
    THEN("We get the request plane") {
      REQUIRE(somePlane->getResourceId() == planeA->getResourceId());
    }
  };
}

TEST_CASE("Given a fresh ResourceModule with 1 unavailable resource",
          "[functional]") {
  vector<Steward*> stewards;
  Pilot *pilot = new Pilot("foo", "bar", 123);
  Pilot *copilot = new Pilot("foo", "bar", 123);
  Steward *steward = new Steward("foo", "bar", "eggs");
  Runway *runway = new Runway("runway");
  Plane *plane = new Plane(2, EnumFlight::COMERCIAL);
  DateTime *departureDate = new DateTime(2000, 1, 1, 0, 0, 0);
  DateTime *returnDate = new DateTime(2000, 1, 3, 0, 0, 0); // 2 days later
  stewards.push_back(steward);
  Flight *flight = new Flight(new Destination("Belo Horizonte", 50), "here",
                              returnDate, departureDate, EnumFlight::COMERCIAL,
                              plane, new Runway("Pista 1"),
                              new BoardingCrew(pilot, copilot, stewards));

  ResourceModule resourceModule =
      ResourceModule({runway}, {plane}, {pilot}, {steward});

  CHECK(resourceModule.getAllFlights().size() == 0);
  resourceModule.saveFlight(flight);
  CHECK(resourceModule.getAllFlights().size() == 1);

  SECTION("When try to get a Resource that is being used at a DateTime.") {
    DateTime someTime = DateTime(2000, 1, 2, 0, 0, 0);
    THEN("We get a No Resource Available error.") {
      REQUIRE_THROWS_WITH(resourceModule.getAvailablePlane(someTime),
                          ResourceNotAvailableErrorMsg);
    }

    SECTION("When free a Flight.") {
      resourceModule.freeFlight(flight);
      THEN("Can use its locked resources again") {
        Plane *returnedPlane = resourceModule.getAvailablePlane(someTime);
      }
    };
  };
}
