#ifndef __SECRETARY_H
#define __SECRETARY_H


#include "OfficeStaff.h"

class Secretary : public OfficeStaff
{

private:




public:
	Secretary(const OfficeStaff& officeStaff);	// Constructor


	// Methods
	void callPatient();


};


#endif // !__SECRETARY_H

