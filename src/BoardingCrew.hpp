#ifndef BOARDINGCREW
#define BOARDINGCREW

#include "Resource.hpp"
#include "Steward.hpp"
#include "Pilot.hpp"

#include <vector> 

using std::vector;


class BoardingCrew: public Resource {
    private:
        Pilot *mainPilot;
        Pilot *copilot;
        vector<Steward*> stewards;
        int numStewards;

    public:
        // BoardingCrew();
        BoardingCrew(Pilot* mainPilot, Pilot* copilot, vector<Steward*> Stewards);
        ~BoardingCrew();

        Pilot* getMainPilot();
        Pilot* getCopilot();
        vector<Steward*> getStewards();
        int getNumStewards();

        void setMainPilot(Pilot* mainPilot);
        void setCopilot(Pilot* copilot);
        void setStewards(Steward* Stewards, int numStewards);
};

#endif
