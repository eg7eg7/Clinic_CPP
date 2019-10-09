#include "Secretary.h"

void Secretary::callPatient(Patient & patient)
{
	//TODO
}

void Secretary::toOs(ostream & os) const
{
	os << "**Secretary**" << endl;
	OfficeStaff::toOs(os);
}
