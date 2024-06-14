#include "BoardingCrew.hpp"
#include <cstring> 


BoardingCrew::BoardingCrew() : Stewards(nullptr), numStewards(0), Resource() {}


BoardingCrew::BoardingCrew(Pilot* mainPilot, Pilot* copilot, Steward* stewards, int numStewards) 
    : MainPilot(mainPilot), Copilot(copilot), numStewards(numStewards),Resource() {
    if (numStewards > 0) {
        Stewards = new Steward[numStewards];
        memcpy(Stewards, stewards, numStewards * sizeof(Steward));
    } else {
        Stewards = nullptr;
    }
}

BoardingCrew::~BoardingCrew() {
    delete[] Stewards;
}


Pilot* BoardingCrew::getMainPilot() {
    return MainPilot;
}


Pilot* BoardingCrew::getCopilot() {
    return Copilot;
}


Steward* BoardingCrew::getStewards() {
    return Stewards;
}


int BoardingCrew::getNumStewards() {
    return numStewards;
}


void BoardingCrew::setMainPilot(Pilot* mainPilot) {
    MainPilot = mainPilot;
}


void BoardingCrew::setCopilot(Pilot* copilot) {
    Copilot = copilot;
}


void BoardingCrew::setStewards(Steward* stewards, int numStewards) {
    delete[] Stewards; 
    this->numStewards = numStewards;
    if (numStewards > 0) {
        Stewards = new Steward[numStewards];
        memcpy(Stewards, stewards, numStewards * sizeof(Steward));
    } else {
        Stewards = nullptr;
    }
}
