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
        //int numStewards;

    public:
        BoardingCrew();
        BoardingCrew(Pilot* mainPilot, Pilot* copilot, vector<Steward*> Stewards);
        ~BoardingCrew();

        Pilot* getMainPilot();
        Pilot* getCopilot();
        vector<Steward*> getStewards();

        void setMainPilot(Pilot* mainPilot);
        void setCopilot(Pilot* copilot);
        void setStewards(Steward* Stewards, int numStewards);

        /* Add a vector of Stewards all at once. */
        void addSteward(vector<Steward*> stewards);

        /* Add a single Steward. */
        void addSteward(Steward* Steward);

        /* Remove a single Steward. */
        void removeSteward(Steward* Steward);

        /* Get number of Stewards */
        int countStewards();

        /* Clear Stewards table */
        int clearStewards();
};

#endif