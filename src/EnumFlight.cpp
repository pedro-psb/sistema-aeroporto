#include "EnumFlight.hpp"

string toString(EnumFlight flight) {
    switch(flight) {
        case EnumFlight::MILITARY: return "Militar";
        case EnumFlight::CARGO: return "Carga";
        case EnumFlight::COMERCIAL: return "Comercial";
        case EnumFlight::BUSINESS: return "Executivo";
        default: return "Unknown";
    }
}

const double getValue(EnumFlight flight) {
    switch(flight) {
        //Tabela de valores
        case EnumFlight::MILITARY: return 12.5;
        case EnumFlight::CARGO: return 7.8;
        case EnumFlight::COMERCIAL: return 45.98;
        case EnumFlight::BUSINESS: return 51.70;
        default: return 0;
    }
}
