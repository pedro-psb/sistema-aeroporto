#ifndef ENUM_SEAT_HPP
#define ENUM_SEAT_HPP
#include <string>
using std::string;

enum class EnumSeat {
  ECONOMY_CLASS,
  PREMIUM_ECONOMY_CLASS,
  BUSINESS_CLASS,
  FIRST_CLASS
};

string toString(EnumSeat seat);
const double getValue(EnumSeat seat);

#endif
