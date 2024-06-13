#include "Client.hpp"
#include "Ticket.hpp"
#include "ResourceModule.hpp"

#ifndef FLIGHT_MOD
#define FLIGHT_MOD


class FlightModule {
private:
  ResourceModule *resourceModule;

public:
  FlightModule(ResourceModule *resourceModule);
  /* Create a valid Flight with no Passangers at a given @dateTime.
   * Raises "NoResourcesAvailable" if some Resource is not available. */

  Flight* createFlight(string originPlace, DateTime* datime, Destination* Destination, EnumFlight flightType);

  /* Cancel a Flight.
   * Should cancel related Tickets and deallocate related Resources. */
  void cancelFlight(Flight* flight);

  /* Adds a @Client to a @Flight..
   * Raises "FlightFullError" if there is no available seats for the flight. */
  void addClientToFlight(Client* client, Flight* flight, EnumSeat seatType);

  /* Removes a @Client from a @Flight. */
  void removeClientFromFlight(Client* client, Flight* flight);
};

#endif
