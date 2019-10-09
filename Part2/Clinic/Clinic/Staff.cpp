#include "Staff.h"

Staff::Staff(const Person& person, long extension, long salary, Room & room) : Person(person), extension(extension), salary(salary) {

		room.addOccupant();
		this->room = &room;
};


void Staff::toOs(ostream & os) const
{
	os << "**Staff**" <<endl;
	Person::toOs(os);
	os << " Extension: " << extension << endl << " Salary : " << salary << endl;
	if (room != nullptr)
		os << *room;
	
}
