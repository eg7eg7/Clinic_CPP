#ifndef __STAFF_H
#define __STAFF_H
#pragma warning(disable: 4996)
#include "Person.h"
#include <iostream>
using namespace std;

class Staff : public Person
{
private:
	long extension;
	long salary;

public:
	Staff(const Person& person, long extension, long salary) : Person(person), extension(extension), salary(salary) {};	//Constructor
	Staff(const Staff& staff) : Person(staff), extension(staff.extension), salary(staff.salary) {};
	virtual ~Staff() {};
	// Getters
	long getExtension() const { return extension; }
	long getSalary() const { return salary; }

	// Setters
	void setSalary(long salary) { this->salary = salary; }

	// Show
	void print() const;
};

#endif // !__STAFF_H
