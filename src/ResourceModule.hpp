#include <vector>

#include "Client.hpp"
#include "Flight.hpp"
#include "FlightSchedule.hpp"
#include "Pilot.hpp"
#include "Plane.hpp"
#include "Resource.hpp"
#include "Runway.hpp"
#include "Steward.hpp"

using std::vector;

#ifndef RESOURCE_MOD
#define RESOURCE_MOD

#define CantCreateResourceErrorMsg "Cannot create resource"

class FlightTable {
private:
  FlightSchedule flightSchedule;
};

class ResourceModule {
private:
  /* The "Source Of Truth" table of the saved Flights. */
  FlightSchedule flightSchedule;

  vector<Resource *> resources;

  // /* The set of resources available. */
  // vector<Steward *> stewardSet;

  // /* The set of planes available. */
  // vector<Plane *> planeSet;

  // /* The set of pilots available. */
  // vector<Pilot *> pilotSet;

  // /* The set of runaways available. */
  // vector<Runway *> runawaySet;

public:
  /* Initializer */
  ResourceModule();

  /* Custom Initializer.
   * Initialze the data by creating N instances of each type of Resource.
   */
  ResourceModule(int N);

  /* Try to get an Resource of @Resource that is available at a given @dateTime.
   * Raises "ResourceNotAvailableError" if its not available at that time */
  virtual Resource *getAvailableResource(Resource resource, DateTime datime);

  /* Free the @resource if its being used during dateTime.
  /* Ignore if the @resource was not begin used at that time. */
  void freeResource(Resource *resource, DateTime dateTime);

  /* Adds a @flight to the flightTable.
   * Raises "FlighAlreadyExistError" if a Flight with the same id already exist.
   */
  void saveFlight(Flight *flight);

  /* Update a @flight (client only). */
  void updateFlight(Flight *flight, vector<Client> clientList);

  /* Deletes a @flight from storage and return it.
   * Ignore if the @flight was not present in the flightTable. */
  void deleteFlight(Flight *flight);

  /* Gets a list of the fixed set of Resources. */
  virtual vector<Resource *> getAllResources();

  /* Get a read-only copy of the flightTable. */
  vector<Flight *> getAllFlights();
};

#endif
