#pragma warning(disable : 4996)
#include "Date.h"

//default constructor
Date::Date() {
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	yr = now->tm_year;
	mon = now->tm_mon;
	day = now->tm_mday;
}

//constructor that takes 3 data members
Date::Date(int m, int d, int y) {
	day = d;
	mon = m;
	yr = y;
}

//method to read date
void Date::readDate(int m, int d, int y) {
	day = d;
	mon = m;
	yr = y;
}

//method to set date
void Date::setDate(int month, int dy, int year) {
	day = dy;
	mon = month;
	yr = year;
}

//method to add one day to a date
void Date::plusoneDate(Date) {
	day = day + 1;
	cout << mon << "/" << day << "/" << yr << endl;
}

//method to get the year
int Date::getYear() const {
	return(yr);
}

//method to get the day
int Date::getDay() const {
	return(day);
}

//method to get the month
int Date::getMonth() const {
	return(mon);
}

//method to put the date
void Date::writeDate() const {
	cout << mon << "/" << day << "/" << yr << endl;
}

//method to determine if a date is valid
void Date::isValid() const {
	if ((mon < 0) || (mon > 12))
		cout << "Month value is invalid!" << endl;
	if ((day < 1) || (day > 31))
		cout << "Day value is invalid!" << endl;
	if ((yr < 1900) || (yr > 2100))
		cout << "Year value is invalid!" << endl;
}