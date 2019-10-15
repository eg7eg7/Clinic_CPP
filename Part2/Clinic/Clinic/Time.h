#pragma once
#include <iostream>
using namespace std;

class Time
{
protected :
	int hours;
	int minutes;
public:
	Time(int hrs = 12, int mins = 0) throw (const char*);
	Time(const Time& other) { *this = other; };
	virtual ~Time() {};

	friend ostream& operator<<(ostream& os, const Time& t);
	int operator<(const Time& t) const;
	int operator>(const Time& t) const;
	const Time& operator=(const Time& t);
	int operator==(const Time& t) const;
	int operator<=(const Time& t) const;
	int operator>=(const Time& t) const;

	int getHour() const { return hours; };
	int getMinute() const { return minutes; };
	static int getTimeDifference(const Time& t1, const Time& t2);

};

