#ifndef __SECRETARY_H
#define __SECRETARY_H

#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#include "OfficeStaff.h"

class Secretary : public OfficeStaff
{
private:
	Secretary(OfficeStaff&& officeStaff);	// move ctor

public:
	Secretary(const OfficeStaff& officeStaff) : Staff(officeStaff), OfficeStaff(officeStaff) {};	// copy ctor
	virtual ~Secretary() {};
	// Methods
	void callPatient();

	virtual void toOs(ostream& os) const override;
};

#endif // !__SECRETARY_H
