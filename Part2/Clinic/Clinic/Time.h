#ifndef __TIME_H
#define __TIME_H
#include <iostream>
#pragma warning(disable : 4290)
using namespace std;

class Time
{
protected:
	int hours;
	int minutes;
public:
	Time(const int& hrs = 0, const int& mins = 0);

	friend ostream& operator<<(ostream& os, const Time& t);

	bool operator<(const Time& t) const;
	bool operator>(const Time& t) const;
	bool operator==(const Time& t) const;
	bool operator<=(const Time& t) const;
	bool operator>=(const Time& t) const;

	const int& getHour() const { return hours; };
	const int& getMinute() const { return minutes; };
	void setHour(const int& h) { hours = h; };
	void setMinute(const int& min) { minutes = min; };
	void setTime(const int& hrs, const int& mins) throw (const char*);

	/* returns difference in minutes between time t1 to t2 */
	static int getTimeDifference(const Time& t1, const Time& t2);
};

#endif //__TIME_H