#include "DateTime.hpp"
using std::string;
using std::to_string;

DateTime::DateTime
	(
		int year,
		int month,
		int day,
		int hours,
		int minutes,
		int seconds
	):
	year (year),
	month (month),
	day (day),
	hours (hours),
	minutes (minutes),
	seconds (seconds)
{}

int DateTime::getYear(){
	return year;
}

int DateTime::getMonth(){
	return month;
}

int DateTime::getDay(){
	return day;
}

int DateTime:: getHours(){
	return hours;
}

int DateTime::getMinutes(){
	return minutes;
}

int DateTime::getSeconds(){
	return seconds;
}

string DateTime::toString(){
	return to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " " +
           to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
}