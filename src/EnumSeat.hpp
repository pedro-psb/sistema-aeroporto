#ifndef ENUM_SEAT_HPP
#define ENUM_SEAT_HPP
#include <string>
using std::string;

enum class EnumSeat {
    ECONOMICA,
    ECONOMICA_PREMIUM,
    EXECUTIVA,
    PRIMEIRA_CLASSE
};

string toString(EnumSeat seat);
const double getValue(EnumSeat seat);

#endif 
