#include "Room.h"

ostream & operator<<(ostream & os, const Room & room)
{
	os << endl <<"**Room**" << endl;
	os << "Room number " << room.getRoomNumber() << endl << "at floor " << room.getFloor() <<
		endl << "Size " << room.getSize() << endl << "Occupied : ";
	if (room.isOccupied())
		os << "Yes";
	else
		os << "No";
	return os << endl;
}
