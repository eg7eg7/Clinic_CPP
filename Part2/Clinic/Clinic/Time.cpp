#include "Time.h"

Time::Time(const int& hrs, const int& mins)
{
	try {
		setTime(hrs, mins);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}

void Time::setTime(const int& hrs, const int& mins) throw (const char*)
{
	if (hrs > 23 || hrs < 0)
	{
		hours = 0;
		minutes = 0;
		throw "Invalid hour";
	}
	if (mins < 0 || mins >59)
	{
		minutes = 0;
		throw "Invalid minutes";
	}
	hours = hrs;
	minutes = mins;
}

int Time::getTimeDifference(const Time& t1, const Time& t2)
{
	int hrs = t2.getHour() - t1.getHour();
	int min = t2.getMinute() - t1.getMinute();

	int totalMinutes = hrs * 60 + min;

	return totalMinutes;
}

bool Time::operator<(const Time & t) const
{
	if (hours < t.hours)
		return true;
	else if (hours == t.hours && minutes < t.minutes)
		return true;
	return false;
}

bool Time::operator>(const Time & t) const
{
	return !operator<(t);
}

bool Time::operator==(const Time & t) const
{
	if (t.hours == hours && t.minutes == minutes)
		return true;
	return false;
}

bool Time::operator<=(const Time & t) const
{
	if (operator<(t) || operator==(t))
		return true;
	return false;
}

bool Time::operator>=(const Time & t) const
{
	if (operator>(t) || operator==(t))
		return true;
	return false;
}

ostream & operator<<(ostream & os, const Time & t)
{
	os << "Time: " << t.hours << ":" << t.minutes << (t.minutes == 0 ? "0" : "");
	return os;
}