#include "Common.hpp"
#include "People.hpp"

class FlightModule {
public:
  /* Adds a @Client to a @Flight..
   * Raises "FlightFullError" if there is no available seats for the flight. */
  void addClientToFlight(Client client, Flight flight);

  /* Removes a @Client from a @Flight. */
  void removeClientFromFlight(Client client, Flight flight);

  /* Create a valid Flight with no Passangers at a given @dateTime.
   * Raises "NoResourcesAvailable" if some Resource is not available. */
  Flight createFlight(DateTime datime);

  /* Cancel a Flight.
   * As a consequence, cancels related Tickets and deallocate related Resources.
   */
  Flight cancelFlight(Flight flight);
};
