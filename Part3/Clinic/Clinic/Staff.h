#ifndef __STAFF_H
#define __STAFF_H

#pragma warning(disable: 4996)
#include <iostream>
#include "Person.h"
#include "Visitor.h"
#include "Room.h"
class Clinic;
using namespace std;
class Staff : public Person, public Visitable
{
protected:
	long extension;
	long salary;
	Room* room;
	Clinic* clinic = nullptr;

public:
	Staff(const Person& person, long extension, long salary, Room & room);	//Constructor
	Staff(const Staff& staff) : Person(staff) { *this = staff; };
	Staff(Staff && staff);
	virtual ~Staff() { room->removeOccupant(); };
	// Getters
	const long& getExtension() const { return extension; }
	const long& getSalary() const { return salary; }
	const Clinic* getClinic() const { return clinic; }

	// Setters
	void setSalary(const long& salary) { this->salary = salary; }
	void setClinic(Clinic* clinic);
	// Show
	virtual void toOs(ostream& os) const override;
	virtual void accept(Visitor* visitor);
	const Staff& operator=(const Staff& other);
};

#endif // !__STAFF_H
