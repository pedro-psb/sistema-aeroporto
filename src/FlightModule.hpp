#include "Client.hpp"
#include "ResourceModule.hpp"

#ifndef FLIGHT_MOD
#define FLIGHT_MOD

#define CantCreateFlightErrorMsg "Cannot create flight."

class FlightModule {
private:
  ResourceModule *resourceModule;

public:
  FlightModule(ResourceModule *resourceModule);
  /* Create a valid Flight with no Passangers at a given @dateTime.
   * Raises "NoResourcesAvailable" if some Resource is not available. */

  Flight *createFlight(DateTime datime);

  /* Cancel a Flight.
   * Should cancel related Tickets and deallocate related Resources. */
  void cancelFlight(Flight flight);

  /* Adds a @Client to a @Flight..
   * Raises "FlightFullError" if there is no available seats for the flight. */
  void addClientToFlight(Client client, Flight flight);

  /* Removes a @Client from a @Flight. */
  void removeClientFromFlight(Client client, Flight flight);
};

#endif
