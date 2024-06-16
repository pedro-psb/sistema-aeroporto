#include "BoardingCrew.hpp"
#include <cstring>

#include <algorithm>

BoardingCrew::BoardingCrew() : stewards({}), Resource() {}

BoardingCrew::BoardingCrew(Pilot *mainPilot, Pilot *copilot,
                           vector<Steward *> stewards)
    : mainPilot(mainPilot), copilot(copilot), stewards(stewards), Resource() {}

Pilot *BoardingCrew::getMainPilot() { return mainPilot; }

Pilot *BoardingCrew::getCopilot() { return copilot; }

vector<Steward *> BoardingCrew::getStewards() { return stewards; }

void BoardingCrew::setMainPilot(Pilot *mainPilot) {
  mainPilot = mainPilot;
  mainPilot = mainPilot;
}

void BoardingCrew::setCopilot(Pilot *copilot) { copilot = copilot; }

void BoardingCrew::addSteward(vector<Steward *> Stewards) {
  stewards.insert(stewards.end(), Stewards.begin(), Stewards.end());
}

void BoardingCrew::addSteward(Steward *steward) { stewards.push_back(steward); }

void BoardingCrew::removeSteward(Steward *steward) {
  auto it = std::find(stewards.begin(), stewards.end(), steward);
  if (it != stewards.end()) {
    stewards.erase(it);
  }
}

int BoardingCrew::countStewards() { return stewards.size(); }

int BoardingCrew::clearStewards() {
  int size;
  size = stewards.size();
  stewards.clear();
  return size;
}
