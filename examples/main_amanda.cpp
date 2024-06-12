#include "includes.hpp"
#include <vector>


using std::cout;
using std::endl;
using std::vector;
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
    Plane *plane1 = new Plane(500, EnumFlight::COMERCIAL);
    Runway *runway = new Runway("Pista 1");

    Pilot *pilot1 = new Pilot("João Silva", "12345678", 123456);
    Pilot *copilot2 = new Pilot("Antonio Rocha", "987654321", 987645);

    cout << "* Pilot ID d1: " << pilot1->getId() << endl;
    cout << "* Pilot ID d2: " << copilot2->getId() << endl;

    // vector<Steward*> stewards = new {};
    // Steward *s1 = new Steward("Ana Julia", "65498731", "Feminino");
    // Steward *s2 = new Steward("Maria Julia", "65498766", "Feminino");
    // stewards.push_back(s1);
    // stewards.push_back(s2);

    // BoardingCrew *crew = new BoardingCrew(pilot1, copilot2, stewards);

    // Flight *flight1 = new Flight(d1, "Sao Paulo", date1, date2, EnumFlight::COMERCIAL, plane1, runway, crew);
    // Client *client1 = new Client("Amanda Fiaux", "12365478978");
    // Ticket *ticket = new Ticket(client1, flight1, 1800.50, EnumSeat::ECONOMICA);

    // cout << "\nFlight Type: " << toString(flight1->getFlightType()) << endl;
    // cout << "\nTicket Type: " << toString(ticket->getSeatType()) << endl;
    // cout << "\nTicket Value: " << getValue(ticket->getSeatType()) << endl;

  return 0;
}
