#include <iostream>
#include <utility>
#include <vector>

#include "Client.hpp"
#include "Flight.hpp"
#include "FlightSchedule.hpp"
#include "Pilot.hpp"
#include "Plane.hpp"
#include "Resource.hpp"
#include "Runway.hpp"
#include "Steward.hpp"

using std::vector, std::cout, std::endl;

#ifndef RESOURCE_MOD
#define RESOURCE_MOD

#define CantCreateResourceErrorMsg "Cannot create resource."
#define NotInStorageErrorMsg "Flight is not in flightSchedule."
#define ResourceNotAvailableErrorMsg "The requested Resource is not available."

class ResourceModule {
private:
  /* The "Source Of Truth" table of the saved Flights. */
  FlightSchedule flightSchedule;

  // We cant use that and return specific Resource type later.
  // For example, if a user gets a generic Resource, it wants
  // to know if its a Plane or Runway, so it can build a Flight.
  //
  // One option to use a generalized resources storage and getter
  // is to return a resource id which is unique among all resources
  // and could move around freely. The downside is that our code
  // is weakly typed and error prone.
  //
  // Another options is to use Templates, but we dont have time to
  // learn in properly.
  vector<Resource *> resources; // deprecated

  /* The set of resources available. */
  vector<Steward *> stewards;

  /* The set of planes available. */
  vector<Plane *> planes;

  /* The set of pilots available. */
  vector<Pilot *> pilots;

  /* The set of runaways available. */
  vector<Runway *> runways;

public:
  /* Initializer */
  ResourceModule();

  /* Custom Initializer. (deprecated, not time to implement that)
   * Initialze the data by passing an intial list of Resources. */
  ResourceModule(vector<Resource *> initialResources);

  /* Custom Initializer.
   * Initialze the data by passing a list of each type of Resource. */
  ResourceModule(vector<Runway *> runways, vector<Plane *> planes,
                 vector<Pilot *> pilots, vector<Steward *> stewards);

  /* Adds a @flight to the flightTable.
   * Raises "FlighAlreadyExistError" if a Flight with the same id already exist.
   */
  void saveFlight(Flight *flight);

  /* Update a @flight (client only). */
  void updateFlight(Flight *flight, vector<Client> clientList);

  /* Frees a @flight from storage and return it.
   * It doesnt free from memory, just from the Resource storage.
   * Throws if the @flight was not present in the flightTable. */
  Flight *freeFlight(Flight *flight);

  /* Gets a list of the fixed set of Resources. */
  virtual vector<Resource *> getAllResources();

  /* Get a read-only copy of the flightTable. */
  vector<Flight *> getAllFlights();

  /* Check if a @date is inside a @dateRage */
  bool isDateInRange(DateTime date, pair<DateTime, DateTime> dateRange);

  /* Try to get a Plane that is available at a given @dateTime.
   * Raises "ResourceNotAvailableError" if its not available at that time */
  Plane *getAvailablePlane(DateTime datime);

  /* Try to get a Pilot that is available at a given @dateTime.
   * Raises "ResourceNotAvailableError" if its not available at that time */
  Pilot *getAvailablePilot(DateTime datime);

  /* Try to get a Steward that is available at a given @dateTime.
   * Raises "ResourceNotAvailableError" if its not available at that time */
  Steward *getAvailableSteward(DateTime datime);

  /* Try to get a Runway that is available at a given @dateTime.
   * Raises "ResourceNotAvailableError" if its not available at that time */
  Runway *getAvailableRunway(DateTime datime);
};

#endif
