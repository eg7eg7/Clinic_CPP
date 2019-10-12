#include "Staff.h"

Staff::Staff(const Person& person, long extension, long salary, Room & room) : Person(person), extension(extension), salary(salary) {
	room.addOccupant();
	this->room = &room;
}
Staff::Staff(Staff && staff) : Person(staff), extension(staff.extension), salary(staff.salary)
{
	room = std::move(staff.room);
	clinic = std::move(staff.clinic);
}


void Staff::setClinic(Clinic * new_clinic)
{
	clinic = new_clinic;
	//func = clinic->addStaff;
	//if (clinic != new_clinic)
	//{
	//	clinic = new_clinic;
	//	if (clinic != nullptr)
	//		clinic->addStaff(this);
	//}
}

void Staff::toOs(ostream & os) const
{
	os << "**Staff**" << endl;
	Person::toOs(os);
	os << " Extension: " << extension << endl << " Salary : " << salary << endl;
	if (room != nullptr)
		os << *room;
}

const Staff & Staff::operator=(const Staff & other)
{
	if (this != &other)
	{
		Person::operator=(other);
		room = other.room;
		extension = other.extension;
		salary = other.salary;
		clinic = other.clinic;
	}
	return *this;
}
