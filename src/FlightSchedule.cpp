#include "FlightSchedule.hpp"
#include <vector>
#include <cstring>
FlightSchedule::FlightSchedule(){

}
FlightSchedule::FlightSchedule(vector<Flight*> flights) : flights(flights) {
 /*   if (numFlights > 0) {//verifica se o nÃºmero Ã© maior que zero, para criar o vetor de voos
        this->flights = new Flight[numFlights];
        memcpy(this->flights, flights, numFlights * sizeof(Flight)); //para mais informaÃ§Ãµes da funÃ§Ã£o: https://www.geeksforgeeks.org/memcpy-in-cc/
    } else {//caso seja menor ou igual a zero, retorna um ponteiro nulo
        this->flights = nullptr;
    }*/
}
vector<Flight*> FlightSchedule::getFlights(){
    return flights;
}
/*void FlightSchedule::setFlights(Flight* flights, int numFlights) {
    delete[] this->flights; //limpa a memoria de flights, caso haja
    this->numFlights = numFlights;

    if (numFlights > 0) {//se o nÃºmero de voos, for maior que zero, gerarÃ¡ o vetor com os voos
        this->flights = new Flight[numFlights];
        memcpy(this->flights, flights, numFlights * sizeof(Flight));
    } else {
        this->flights = nullptr;
    }
}*/
        /* Add a vector of flights all at once. */
        void addFlight(vector<Flight*> flights){
            flights=flights;
        }

        /* Add a single flight. */
        void addFlight(Flight* flight){
            flights.push_back(flight);
        }

        /* Remove a single flight. */
        void removeFlight(Flight* flight){
             flights.erase(std::remove(flights.begin(), flights.end(), flight), flights.end());

        }

        /* Get number of flights */
        int count(){
            return flights.size();
        }

        /* Clear flights table */
        int clearFlights(){
            int size;
            size=flights.size();
            flights.clear();
            return size;
        }