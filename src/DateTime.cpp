#include "DateTime.hpp"
using std::string;

DateTime::DateTime
	(
		int year,
		int month,
		int day,
		int houns,
		int minutes,
		int seconds
	):
	year (year),
	month (month),
	day (day),
	houns (houns),
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

int DateTime:: getHouns(){
	return houns;
}

int DateTime::getMinutes(){
	return minutes;
}

int DateTime::getSeconds(){
	return seconds;
}
