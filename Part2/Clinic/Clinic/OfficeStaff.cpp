#include "OfficeStaff.h"



void OfficeStaff::toOs(ostream & os) const
{
	os << "**OfficeStaff**" << endl;
	Staff::toOs(os);
}