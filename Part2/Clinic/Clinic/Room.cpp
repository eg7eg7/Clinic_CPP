#include "Room.h"

ostream & operator<<(ostream & os, const Room & room)
{
	os << endl <<"**Room**" << endl;
	os << " Room number " << room.getRoomNumber() << endl << " floor " << room.getFloor() <<
		endl << " size " << room.getSize() << endl << " occupied : ";
	if (room.isOccupied())
		os << "Yes";
	else
		os << "No";
	return os << endl;
}
