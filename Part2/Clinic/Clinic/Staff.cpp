#include "Staff.h"

Staff::Staff(const Person& person, long extension, long salary, Room & room) : Person(person), extension(extension), salary(salary) {
	room.addOccupant();
	this->room = &room;
};

void Staff::setClinic(Clinic * new_clinic)
{
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