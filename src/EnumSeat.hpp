#ifndef ENUM_SEAT_HPP
#define ENUM_SEAT_HPP

enum class EnumSeat {
    ECONOMICA,
    ECONOMICA_PREMIUM,
    EXECUTIVA,
    PRIMEIRA_CLASSE
};

const char* toString(EnumSeat seat);
const double getValue(EnumSeat seat);

#endif 
