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
		
    public:
		string name;
        Destination(string name, double distance);
    	int getId();
    	double getDistance();
};
#endif