#ifndef PLANE
#define PLANE
#include "Resources.hpp"
#include "Steward.hpp"
//#include "Pilot.hpp"
class BoardingCrew: public Resources{
    private:
        //Pilot MainPilot;
        //Pilot Copilot;
        Steward Stewards[];
    public:
        Pilot getMainPilot();
        Pilot getCopilot();
        Steward getStewards();
}
#endif