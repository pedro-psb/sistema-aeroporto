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

const double getValue(EnumFlight flight) {
    switch(flight) {
        //Tabela de valores
        case EnumFlight::MILITAR: return 12.5;
        case EnumFlight::CARGA: return 7.8;
        case EnumFlight::COMERCIAL: return 45.98;
        case EnumFlight::EXECUTIVO: return 51.70;
        default: return 0;
    }
}
