#include "EnumFlight.hpp"

const char* toString(EnumFlight flight) {
    switch(flight) {
        case EnumFlight::MILITAR: return "Militar";
        case EnumFlight::CARGA: return "Carga";
        case EnumFlight::COMERCIAL: return "Comercial";
        case EnumFlight::EXECUTIVO: return "Executivo";
        default: return "Unknown";
    }
}