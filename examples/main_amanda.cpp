#include "includes.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    Destination *d1 = new Destination("Belo Horizonte", 50);
    Destination *d2 = new Destination("Justinopolis", 50);
    Destination *d3 = new Destination("Vale Verde", 80);

    DateTime *date1 = new DateTime(2024, 6, 9, 15, 18, 00);
    DateTime *date2 = new DateTime(2024, 7, 25, 7, 00, 00);

    Plane *planeComercial = new Plane(500, EnumFlight::COMERCIAL);
    Plane *planeExecutivo = new Plane(20, EnumFlight::EXECUTIVO);

    Runway *runway = new Runway("Pista 1");

    Pilot *pilot1 = new Pilot("João Silva", "12345678", 123456);
    Pilot *copilot2 = new Pilot("Antonio Rocha", "987654321", 987645);

    Steward *s1 = new Steward("Ana Julia", "65498731", "Feminino");
    Steward *s2 = new Steward("Maria Julia", "65498766", "Feminino");

    BoardingCrew *crew = new BoardingCrew(pilot1, copilot2, s1, 5);

    Client *client1 = new Client("Amanda Fiaux", "12365478978");
    Client *client2 = new Client("Pedro Pessoa", "12365478978");
    Client *client3 = new Client("Glaucus Miranda", "12365478978");

    ResourceModule* resourceModule = new ResourceModule();
    FlightModule flightModule(resourceModule);
    Flight* flight = flightModule.createFlight("Sao Paulo", date1, d1, EnumFlight::COMERCIAL);
    flightModule.addClientToFlight(client1, flight, EnumSeat::ECONOMICA);
    flightModule.addClientToFlight(client2, flight, EnumSeat::PRIMEIRA_CLASSE);
    flightModule.addClientToFlight(client3, flight, EnumSeat::EXECUTIVA);

    flightModule.removeClientFromFlight(client3, flight);

    if (flight != nullptr) {
           	cout << "Flight created successfully!" << endl;
            flight->printFlight();
    } else {
        cout << "Failed to create flight." << endl;
    }

  return 0;
}
