#ifndef DATETIME
#define DATETIME
#include <string>
using std::string;

class DateTime
{
	private:
		int year;
		int month;
		int day;
		int houns;
		int minutes;
		int seconds;
		
    public:
        DateTime
        (
			int year,
			int month,
			int day,
			int houns,
			int minutes,
			int seconds
		);
};
#endif