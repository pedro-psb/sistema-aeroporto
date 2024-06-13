#ifndef DESTINATION
#define DESTINATION
#include <string>
using std::string;
class Destination
{
	private:
		int id;
		static int currentId;
		double distance;
		string name;
		
    public:
        Destination(string name, double distance);
    	int getId();
    	double getDistance();
    	string getName();
};
#endif