#include "FlightSchedule.hpp"
#include <algorithm>

FlightSchedule::FlightSchedule() {
  flights = vector<Flight *>(); // cria o vetor vazio
}

FlightSchedule::FlightSchedule(vector<Flight *> flights) : flights(flights) {}

vector<Flight *> FlightSchedule::getFlights() { return flights; }

void FlightSchedule::addFlight(vector<Flight *> Flights) {
  flights.insert(flights.end(), Flights.begin(), Flights.end());
}

void FlightSchedule::addFlight(Flight *flight) { flights.push_back(flight); }

void FlightSchedule::removeFlight(Flight *flight) {
  auto it = std::find(flights.begin(), flights.end(), flight);
  if (it != flights.end()) {
    flights.erase(it);
  }
}

int FlightSchedule::count() { return flights.size(); }

int FlightSchedule::clearFlights() {
  int size;
  size = flights.size();
  flights.clear();
  return size;
}
