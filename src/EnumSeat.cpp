#include "EnumSeat.hpp"

string toString(EnumSeat seat) {
  switch (seat) {
  case EnumSeat::ECONOMY_CLASS:
    return "Economica";
  case EnumSeat::PREMIUM_ECONOMY_CLASS:
    return "Economica Premium";
  case EnumSeat::BUSINESS_CLASS:
    return "Executiva";
  case EnumSeat::FIRST_CLASS:
    return "Primeira Classe";
  default:
    return "Unknown";
  }
}

const double getValue(EnumSeat seat) {
  switch (seat) {
  // Tabela de valores
  case EnumSeat::ECONOMY_CLASS:
    return 500;
  case EnumSeat::PREMIUM_ECONOMY_CLASS:
    return 800;
  case EnumSeat::BUSINESS_CLASS:
    return 1500;
  case EnumSeat::FIRST_CLASS:
    return 2030;
  default:
    return 0;
  }
}
