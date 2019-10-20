#include "OfficeStaff.h"

OfficeStaff::OfficeStaff(const OfficeStaff & other) : Staff(other)
{
	*this = other;
}

OfficeStaff::OfficeStaff(OfficeStaff && other) : Staff(std::move(other))
{
	room = std::move(other.room);
}

OfficeStaff::~OfficeStaff()
{
	if (room != nullptr)
		room->addOccupant();
}
const OfficeStaff & OfficeStaff::operator=(const OfficeStaff & other)
{
	if (this != &other)
	{
		Staff::operator=(other);
		room = other.room;
	}
	return *this;
}

void OfficeStaff::toOs(ostream & os) const
{
	os << "**OfficeStaff**" << endl;
	Staff::toOs(os);
}