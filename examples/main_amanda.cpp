#include "includes.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
    // Testando id
    Destination *d1 = new Destination("Belo Horizonte", 50);
    Destination *d2 = new Destination("Justinopolis", 50);
    Destination *d3 = new Destination("Vale Verde", 80);

    cout << "* ID d1: " << d1->getId() << endl;
    cout << "* ID d2: " << d2->getId() << endl;
    cout << "* ID d3: " << d3->getId() << endl;

    // Testando Enums
    DateTime *date1 = new DateTime(2024, 6, 9, 15, 18, 00);
    DateTime *date2 = new DateTime(2024, 7, 9, 15, 18, 00);
    // AQUI: construtor com 5 argumentos, precisa passar runaway, steward, etc
    // Flight *flight1 = new Flight(d1, "Sao Paulo", date1, date2, EnumFlight::COMERCIAL);
    Client *client1 = new Client("Amanda Fiaux", "12365478978");
    // Ticket *ticket = new Ticket(client1, flight1, 1800.50, EnumSeat::ECONOMICA);

    // cout << "\nFlight Type: " << toString(flight1->getFlightType()) << endl;
    // cout << "\nTicket Type: " << toString(ticket->getSeatType()) << endl;
    // cout << "\nTicket Value: " << getValue(ticket->getSeatType()) << endl;

  return 0;
}
