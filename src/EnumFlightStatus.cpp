#include "EnumFlightStatus.hpp"

const string toString(EnumFlightStatus flightStatus) {
  switch (flightStatus) {
  case EnumFlightStatus::SCHEDULED:
    return "Agendado";
  case EnumFlightStatus::CONFIRMED:
    return "Confirmado";
  case EnumFlightStatus::IN_FLIGHT:
    return "Em Vôo";
  case EnumFlightStatus::COMPLETED:
    return "Completo";
  case EnumFlightStatus::CANCELLED:
    return "Cancelado";
  default:
    return "Unknown";
  }
}