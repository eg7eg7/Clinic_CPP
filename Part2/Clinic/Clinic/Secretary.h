#ifndef __SECRETARY_H
#define __SECRETARY_H
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#include "OfficeStaff.h"

class Secretary : public OfficeStaff
{
private:

public:
	Secretary(const OfficeStaff& officeStaff) : Staff(officeStaff), OfficeStaff(officeStaff) {};	// Constructor

	// Methods
	void callPatient();
};

#endif // !__SECRETARY_H
