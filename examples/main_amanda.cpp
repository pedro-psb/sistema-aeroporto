#include "includes.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    Destination *d1 = new Destination("Belo Horizonte", 50);
    DateTime *date1 = new DateTime(2024, 6, 9, 15, 18, 00);
    Client *client1 = new Client("Amanda Fiaux", "12365478978", "A753M");
    Client *client2 = new Client("Pedro Pessoa", "12365478978", "P783M");
    Client *client3 = new Client("Glaucus Miranda", "12365478978", "G908F");

    ResourceModule* resourceModule = new ResourceModule();
    FlightModule flightModule(resourceModule);
    Flight* flight = flightModule.createFlight("Sao Paulo", date1, d1, EnumFlight::COMERCIAL);

    if (flight != nullptr) {
           	cout << "----- Flight created successfully! -----" << endl;
            flight->printFlight();
    } else {
        cout << "----- Failed to create flight. -----" << endl;
    }

    flightModule.addClientToFlight(client1, flight, EnumSeat::ECONOMICA);
    flightModule.addClientToFlight(client2, flight, EnumSeat::PRIMEIRA_CLASSE);
    flightModule.addClientToFlight(client3, flight, EnumSeat::EXECUTIVA);
    flight->printTickets();
    // flightModule.removeClientFromFlight(client3, flight);
    flight->printFlight();
    flightModule.cancelFlight(flight);
    flight->printFlight();





  return 0;
}
