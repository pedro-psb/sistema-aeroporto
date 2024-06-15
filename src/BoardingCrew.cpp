#include "BoardingCrew.hpp"
#include <cstring> 


BoardingCrew::BoardingCrew() : stewards({}), Resource() {}


BoardingCrew::BoardingCrew(Pilot* mainPilot, Pilot* copilot, vector<Steward*> stewards) 
    : mainPilot(mainPilot), copilot(copilot), stewards(stewards), Resource() {
}

BoardingCrew::~BoardingCrew() {
    // delete[] stewards;
}


Pilot* BoardingCrew::getMainPilot() {
    return mainPilot;
}


Pilot* BoardingCrew::getCopilot() {
    return copilot;
}


vector<Steward*> BoardingCrew::getStewards() {
    return stewards;
}


int BoardingCrew::getNumStewards() {
    return numStewards;
}


void BoardingCrew::setMainPilot(Pilot* mainPilot) {
    mainPilot = mainPilot;
}


void BoardingCrew::setCopilot(Pilot* copilot) {
    copilot = copilot;
}


// void BoardingCrew::setStewards(vector<Steward*> stewards) {
    // delete[] Stewards; 
    // this->numStewards = numStewards;
    // if (numStewards > 0) {
    //     Stewards = new Steward[numStewards];
    //     memcpy(Stewards, stewards, numStewards * sizeof(Steward));
    // } else {
    //     Stewards = nullptr;
    // }
// }
