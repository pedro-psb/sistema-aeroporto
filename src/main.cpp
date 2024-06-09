#include "includes.hpp"

using std::cout;
using std::endl;
using std::string;

const char* toString(EnumFlight flight) {
    switch(flight) {
        case EnumFlight::MILITAR: return "Militar";
        case EnumFlight::CARGA: return "Carga";
        case EnumFlight::COMERCIAL: return "Comercial";
        case EnumFlight::EXECUTIVO: return "Executivo";
        default: return "Unknown";
    }
}

const char* toString(EnumSeat flight) {
    switch(flight) {
        case EnumSeat::ECONOMICA: return "Economica";
        case EnumSeat::ECONOMICA_PREMIUM: return "Economica Premiun";
        case EnumSeat::EXECUTIVA: return "Executiva";
        case EnumSeat::PRIMEIRA_CLASSE: return "Primeira Classe";
        default: return "Unknown";
    }
}

const double getValue(EnumSeat flight) {
    switch(flight) {
        case EnumSeat::ECONOMICA: return 1500;
        case EnumSeat::ECONOMICA_PREMIUM: return 1800;
        case EnumSeat::EXECUTIVA: return 2000.50;
        case EnumSeat::PRIMEIRA_CLASSE: return 2450.70;
        default: return 0;
    }
}

int main()
{
    //Testando id 
    Destination* d1 =  new Destination("Belo Horizonte", 50);
    Destination* d2 = new Destination("Justinopolis", 50);
    Destination* d3 = new Destination("Vale Verde", 80);

    cout << "ID d1: " << d1->getId() << endl;
    cout << "ID d2: " << d2->getId() << endl;
    cout << "ID d3: " << d3->getId() << endl;

    //Testando Enums
    DateTime* date1 = new DateTime(2024, 6, 9, 15, 18, 00);
    DateTime* date2 = new DateTime(2024, 7, 9, 15, 18, 00);
    Flight* flight1 = new Flight(d1, "Sao Paulo", date1, date2, EnumFlight::COMERCIAL);
    Client* client1 = new Client("Amanda Fiaux", "12365478978");
    Ticket* ticket = new Ticket(client1, flight1, 1800.50, EnumSeat::ECONOMICA);

    cout << "\nFlight Type: " << toString(flight1->getFlightType()) << endl;
    cout << "\nTicket Type: " << toString(ticket->getSeatType()) << endl;
    cout << "\nTicket Value: " << getValue(ticket->getSeatType()) << endl;




    return 0;
}
