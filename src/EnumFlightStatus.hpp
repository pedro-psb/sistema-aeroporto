#ifndef ENUM_FLIGHT_STATUS
#define ENUM_FLIGHT_STATUS
#include <string>
using std::string;

enum class EnumFlightStatus {
  SCHEDULED,
  CONFIRMED,
  IN_FLIGHT,
  COMPLETED,
  CANCELLED
};

const string toString(EnumFlightStatus flightStatus);

#endif