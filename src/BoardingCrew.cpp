#include "BoardingCrew.hpp"
#include <cstring> 

BoardingCrew::BoardingCrew(Pilot* mainPilot, Pilot* copilot, vector<Steward*> stewards) 
    : mainPilot(mainPilot), copilot(copilot), stewards(stewards), Resource() {
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