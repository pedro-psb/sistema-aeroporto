#ifndef DESTINATION
#define DESTINATION
#include <string>
using std::string;
class Destination
{
	private:
		int id;
		static int currentId;
		float distance;
		
    public:
		string name;
        Destination(string name, float distance);
    	int getId() const;
};
#endif