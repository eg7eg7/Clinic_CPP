#ifndef __STAFF_H
#define __STAFF_H

#pragma warning(disable: 4996)
#include "Person.h"
#include "Room.h"
#include <iostream>
using namespace std;

class Staff : public Person
{
protected:
	long extension;
	long salary;
	Room* room;

	
public:
	Staff(const Person& person, long extension, long salary, Room & room);	//Constructor
	Staff(const Staff& staff) : Person(staff) { room = staff.room; };
	Staff(Staff && staff) : Person(staff), extension(staff.extension), salary(staff.salary) 
	{
		room = std::move(staff.room);
	};
	virtual ~Staff() { room->removeOccupant(); };
	// Getters
	long getExtension() const { return extension; }
	long getSalary() const { return salary; }

	// Setters
	void setSalary(long salary) { this->salary = salary; }

	// Show
	virtual void toOs(ostream& os) const override;
};

#endif // !__STAFF_H
