#pragma message("Adding Secretary")
#ifndef __SECRETARY_H
#define __SECRETARY_H

#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#include "OfficeStaff.h"
#include "Turn.h"

class Secretary : public OfficeStaff
{
public:
	Secretary(OfficeStaff & officeStaff) : Staff(officeStaff), OfficeStaff(officeStaff) {};
	// Methods
	void callPatient(Patient & patient) const;

	virtual void toOs(ostream& os) const override;
};

#endif // !__SECRETARY_H
