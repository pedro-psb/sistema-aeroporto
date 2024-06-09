#ifndef ENUM_FLIGHT
#define ENUM_FLIGHT

enum class EnumFlight {
    MILITAR,
    CARGA,
    COMERCIAL,
    EXECUTIVO
};

const char* toString(EnumFlight flight);

#endif 