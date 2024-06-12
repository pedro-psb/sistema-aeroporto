#include "Client.hpp"
#include "Destination.hpp"
#include "Ticket.hpp"
#include "Flight.hpp"

#ifndef SALES_MOD
#define SALES_MOD

class SaleModule {
public:
  /* Get next available Flight going to @Destination.
   * Raises NoFlightAvailable if there is no next flight available. */
  Flight getNextFlightTo(Destination destination);

  /* Process a @Flight Ticket purchase for @Client.
   * Raises NoFlightAvailable if there is no next flight available. */
  Ticket processTicket(Client client, Flight flight);

  /* Cancel Ticket associated with Client and Flight. */
  void cancelTicket(Ticket ticket);
};

#endif
