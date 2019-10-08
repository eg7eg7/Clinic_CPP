#include "Staff.h"


void Staff::toOs(ostream & os) const
{
	os << "\n Extension: " << extension << endl << " Salary : " << salary << endl;
}
