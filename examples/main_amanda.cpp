#include "includes.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  Destination *destination = new Destination("Belo Horizonte", 50);
  DateTime *departureDate = new DateTime(2024, 6, 9, 15, 18, 00);

  Plane *plane = new Plane(10, EnumFlight::COMERCIAL);
  Pilot *pilot = new Pilot("João Silva", "123654", 123);
  Pilot *copilot = new Pilot("Erick Rocha", "987564", 123);
  Steward *stewardA = new Steward("steward A", "123456", "F");
  Steward *stewardB = new Steward("steward B", "654987", "F");
  Runway *runwayA = new Runway("runway");
  ResourceModule *resourceModule = new ResourceModule(
      {runwayA}, {plane}, {pilot, copilot}, {stewardA, stewardB});
  FlightModule flightModule(resourceModule);

  cout << resourceModule->getAllResources().size() << endl;

  Client *client1 = new Client("Amanda Fiaux", "12365478978", "A753M");
  Client *client2 = new Client("Pedro Pessoa", "12365478978", "P783M");
  Client *client3 = new Client("Glaucus Miranda", "12365478978", "G908F");

  try {
    Flight *flight = flightModule.createFlight(
        "Sao Paulo", departureDate, destination, EnumFlight::COMERCIAL);
    flight->printFlight();

    flightModule.addClientToFlight(client1, flight, EnumSeat::ECONOMY_CLASS);
    flightModule.addClientToFlight(client2, flight, EnumSeat::FIRST_CLASS);
    flightModule.addClientToFlight(client3, flight, EnumSeat::BUSINESS_CLASS);
    flight->printTickets();
    // flightModule.removeClientFromFlight(client3, flight);
    flight->printFlight();

    cout << "----- Canceling Flight... -----" << endl;
    flightModule.cancelFlight(flight);
    flight->printFlight();
  } catch (const char *msg) {
    std::cerr << "Erro: " << msg << std::endl;
  }

  return 0;
}
