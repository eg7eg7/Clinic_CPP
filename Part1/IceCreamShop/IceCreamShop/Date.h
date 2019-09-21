#pragma once
#ifndef _DATE
#define _DATE
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
class Date {
public:
	Date();
	Date(int, int, int);
	void readDate(int, int, int);
	void setDate(int, int, int);
	void plusoneDate(Date);
	int getYear() const;
	int getDay() const;
	int getMonth() const;
	void writeDate() const;
	void isValid() const;

private:
	int day, mon, yr;
};
#endif