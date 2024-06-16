#include "Flight.hpp"

#include <vector>
using std::vector;

#ifndef FLIGHTSCHEDULE
#define FLIGHTSCHEDULE

class FlightSchedule {
private:
  vector<Flight *> flights;

public:
  /* Create FlightSchedule with empty */
  FlightSchedule();

  /* Create FlightSchedule with initial flight vector */
  FlightSchedule(vector<Flight *> flights);

  /* Get a read-only copy of all flights. */
  vector<Flight *> getFlights();

  /* Add a vector of flights all at once. */
  void addFlight(vector<Flight *> flights);

  /* Add a single flight. */
  void addFlight(Flight *flight);

  /* Remove a single flight. */
  void removeFlight(Flight *flight);

  /* Get number of flights */
  int count();

  /* Clear flights table */
  int clearFlights();
};
#endif
