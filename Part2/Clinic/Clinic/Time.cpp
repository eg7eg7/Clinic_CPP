#include "Time.h"


Time::Time(int hrs, int mins) throw (const char*)
{
	if (hrs > 23 || hrs < 0)
		throw "Invalid hour";
	if (mins < 0 || mins >59)
		throw "Invalid minutes";
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



int Time::operator<(const Time & t) const
{
	if (hours < t.hours)
		return 1;
	else if (hours == t.hours)
	{
		if (minutes < t.minutes)
			return 1;
		else if (minutes == t.minutes)
			return 0;
		else return -1;
	}
	else
		return -1;
}

int Time::operator>(const Time & t) const
{
	return -1 * operator<(t);
}

const Time& Time::operator=(const Time & t)
{
	if (this != &t)
	{
		hours = t.hours;
		minutes = t.minutes;
	}
	return *this;
}

int Time::operator==(const Time & t) const
{
	if (t.hours == hours && t.minutes == minutes)
		return 1;
	return 0;
}

int Time::operator<=(const Time & t) const
{
	if (operator<(t) || operator==(t))
		return 1;
	return 0;
}

int Time::operator>=(const Time & t) const
{
	if (operator>(t) || operator==(t))
		return 1;
	return 0;
}

ostream & operator<<(ostream & os, const Time & t)
{
	os << "Time: "<< t.hours << ":" << t.minutes << endl;
	return os;
}

