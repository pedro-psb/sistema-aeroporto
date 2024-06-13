#include "EnumSeat.hpp"

string toString(EnumSeat seat) {
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
        //Tabela de valores
        case EnumSeat::ECONOMICA: return 500;
        case EnumSeat::ECONOMICA_PREMIUM: return 800;
        case EnumSeat::EXECUTIVA: return 1500;
        case EnumSeat::PRIMEIRA_CLASSE: return 2030;
        default: return 0;
    }
}
