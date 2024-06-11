#include <vector>

#include "Common.hpp"
#include "People.hpp"
#include "Resource.hpp"

using std::vector;

#ifndef RESOURCE_MOD
#define RESOURCE_MOD

#define CantCreateResourceErrorMsg "Cannot create resource"

class FlightTable {
private:
  vector<Flight> internalStorage;
};

class ResourceModule {
private:
  /* The "Source Of Truth" table of the saved Flights. */
  vector<Flight> flightTable;

public:
  /* Initializer */
  ResourceModule();

  /* Try to get a Resource of @ResourceType for a given @dateTime
   * Raises "ResourceNotAvailableError" if its not available at that time */
  virtual Resource *getResource(ResourceType resourceType, DateTime datime);

  /* Free the @resource if its being used during dateTime.
  /* Ignore if the @resource was not begin used at that time. */
  void freeResource(Resource resource, DateTime dateTime);

  /* Adds a @flight to the flightTable.
   * Raises "FlighAlreadyExistError" if a Flight with the same id already exist.
   */
  void saveFlight(Flight flight);

  /* Update a @flight (client only). */
  void updateFlight(Flight flight, vector<Client> clientList);

  /* Deletes a @flight.
   * Ignore if the @flight was not present in the flightTable. */
  void deleteFlight(Flight flight);

  /* Get a read-only copy of the flightTable. */
  vector<Flight> getFlightTable();
};

#endif
