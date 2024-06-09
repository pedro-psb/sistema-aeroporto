#include "FlightSchedule.hpp"
#include <cstring>
FlightSchedule::FlightSchedule(){

}
FlightSchedule::FlightSchedule(Flight* flights, int numFlights) : numFlights(numFlights) {
    if (numFlights > 0) {//verifica se o número é maior que zero, para criar o vetor de voos
        this->flights = new Flight[numFlights];
        memcpy(this->flights, flights, numFlights * sizeof(Flight)); //para mais informações da função: https://www.geeksforgeeks.org/memcpy-in-cc/
    } else {//caso seja menor ou igual a zero, retorna um ponteiro nulo
        this->flights = nullptr;
    }
}
Flight* FlightSchedule::getFlights(){
    return flights;
}
void FlightSchedule::setFlights(Flight* flights, int numFlights) {
    delete[] this->flights; //limpa a memoria de flights, caso haja
    this->numFlights = numFlights;

    if (numFlights > 0) {//se o número de voos, for maior que zero, gerará o vetor com os voos
        this->flights = new Flight[numFlights];
        memcpy(this->flights, flights, numFlights * sizeof(Flight));
    } else {
        this->flights = nullptr;
    }
}