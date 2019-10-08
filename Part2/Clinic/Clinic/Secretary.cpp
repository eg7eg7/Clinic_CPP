#include "Secretary.h"

void Secretary::callPatient()
{
	//TODO
}

void Secretary::toOs(ostream & os) const
{
	os << "**Secretary**" << endl;
	OfficeStaff::toOs(os);
}
