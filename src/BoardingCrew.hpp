#ifndef BOARDINGCREW
#define BOARDINGCREW

#include "Resource.hpp"
#include "Steward.hpp"
#include "Pilot.hpp"

class BoardingCrew: public Resource {
    private:
        Pilot *MainPilot;
        Pilot *Copilot;
        Steward* Stewards;
        int numStewards;

    public:
        BoardingCrew();
        BoardingCrew(Pilot* MainPilot, Pilot* Copilot, Steward* Stewards, int numStewards);
        ~BoardingCrew();

        Pilot* getMainPilot();
        Pilot* getCopilot();
        Steward* getStewards();
        int getNumStewards();

        void setMainPilot(Pilot* MainPilot);
        void setCopilot(Pilot* Copilot);
        void setStewards(Steward* Stewards, int numStewards);
};

#endif
