#ifndef BOARDINGCREW
#define BOARDINGCREW
#include "Resources.hpp"
#include "Steward.hpp"
#include "Pilot.hpp"
class BoardingCrew: public Resources{
    private:
        Pilot MainPilot;
        Pilot Copilot;
        Steward Stewards[];
    public:
        BoardingCrew();
        BoardingCrew(Pilot MainPilot, Pilot Copilot, Steward* Stewards);
        Pilot getMainPilot();
        Pilot getCopilot();
        Steward getStewards();
        void setMainPilot(Pilot MainPilot);
        void setCopilot(Pilot Copilot);
        void setStewards(Steward* Stewards);
};
#endif