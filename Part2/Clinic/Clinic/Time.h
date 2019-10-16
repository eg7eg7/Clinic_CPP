#ifndef __TIME_H
#define __TIME_H
#include <iostream>
using namespace std;

class Time
{
protected :
	int hours;
	int minutes;
public:
	Time(int hrs = 0, int mins = 0) throw (const char*);
	Time(const Time& other) { *this = other; };
	virtual ~Time() {};

	friend ostream& operator<<(ostream& os, const Time& t);
	bool operator<(const Time& t) const;
	bool operator>(const Time& t) const;
	const Time& operator=(const Time& t);
	bool operator==(const Time& t) const;
	bool operator<=(const Time& t) const;
	bool operator>=(const Time& t) const;

	int getHour() const { return hours; };
	int getMinute() const { return minutes; };

	//returns value in minutes
	static int getTimeDifference(const Time& t1, const Time& t2);

};

#endif //__TIME_H