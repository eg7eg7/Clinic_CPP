#include "Staff.h"


void Staff::toOs(ostream & os) const
{
	os << "**Staff**" << endl << "Extension: " << extension << endl << "Salary : " << salary << endl;
}
