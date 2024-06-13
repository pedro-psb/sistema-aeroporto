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
		int hours;
		int minutes;
		int seconds;
		
    public:
        DateTime
        (
			int year,
			int month,
			int day,
			int hours,
			int minutes,
			int seconds
		);
		
		int getYear();
		int getMonth();
		int getDay();
		int getHours();
		int getMinutes();
		int getSeconds();
		string toString();
};
#endif