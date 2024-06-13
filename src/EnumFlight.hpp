#ifndef ENUM_FLIGHT
#define ENUM_FLIGHT
#include <string>
using std::string;

enum class EnumFlight {
    MILITAR,
    CARGA,
    COMERCIAL,
    EXECUTIVO
};

string toString(EnumFlight flight);
const double getValue(EnumFlight seat);

#endif 