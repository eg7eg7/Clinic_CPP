#ifndef __TIME_H
#define __TIME_H
#include <iostream>
#include <string>
using namespace std;

class Time
{
protected:
	int hours;
	int minutes;
public:
	Time(const int& hrs = 0, const int& mins = 0);
	Time(const Time& other) { *this = other; };
	~Time() {};

	friend ostream& operator<<(ostream& os, const Time& t);
	bool operator<(const Time& t) const;
	bool operator>(const Time& t) const;
	const Time& operator=(const Time& t);
	bool operator==(const Time& t) const;
	bool operator<=(const Time& t) const;
	bool operator>=(const Time& t) const;

	const int& getHour() const { return hours; };
	const int& getMinute() const { return minutes; };
	void setHour(const int& h) { hours = h; };
	void setMinute(const int& min) { minutes = min; };
	void setTime(const int& hrs, const int& mins);
	//returns value in minutes
	static int getTimeDifference(const Time& t1, const Time& t2);
};

#endif //__TIME_H