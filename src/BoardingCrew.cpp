#include "BoardingCrew.hpp"
#include <cstring> 
#include <algorithm>

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


/*int BoardingCrew::getNumStewards() {
    return numStewards;
}*/


void BoardingCrew::setMainPilot(Pilot* mainPilot) {
    mainPilot = mainPilot;
    mainPilot = mainPilot;
}


void BoardingCrew::setCopilot(Pilot* copilot) {
    copilot = copilot;
    copilot = copilot;
}

 /* Add a vector of Stewards all at once. */
        void BoardingCrew::addSteward(vector<Steward*> Stewards){
            stewards.insert(stewards.end(), Stewards.begin(), Stewards.end());
        }

        /* Add a single Steward. */
        void BoardingCrew::addSteward(Steward* steward){
            stewards.push_back(steward);
        }

        /* Remove a single Steward. */
        void BoardingCrew::removeSteward(Steward* steward){
            auto it = std::find(stewards.begin(), stewards.end(), steward);
                if (it != stewards.end()) {
                    stewards.erase(it);
                }
        }

        /* Get number of Stewards */
        int BoardingCrew::countStewards(){
            return stewards.size();
        }

        /* Clear Stewards table */
        int BoardingCrew::clearStewards(){
              int size;
              size = stewards.size();
              stewards.clear();
              return size;
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