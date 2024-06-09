#include "EnumSeat.hpp"

const char* toString(EnumSeat seat) {
    switch(seat) {
        case EnumSeat::ECONOMICA: return "Economica";
        case EnumSeat::ECONOMICA_PREMIUM: return "Economica Premium";
        case EnumSeat::EXECUTIVA: return "Executiva";
        case EnumSeat::PRIMEIRA_CLASSE: return "Primeira Classe";
        default: return "Unknown";
    }
}

const double getValue(EnumSeat seat) {
    switch(seat) {
        case EnumSeat::ECONOMICA: return 1500;
        case EnumSeat::ECONOMICA_PREMIUM: return 1800;
        case EnumSeat::EXECUTIVA: return 2000.50;
        case EnumSeat::PRIMEIRA_CLASSE: return 2450.70;
        default: return 0;
    }
}
