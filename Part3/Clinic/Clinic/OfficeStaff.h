#ifndef __OFFICESTAFF_H
#define __OFFICESTAFF_H
#pragma warning(disable: 4996)

#include <iostream>
using namespace std;
#include "Patient.h"

class OfficeStaff : virtual public Staff
{
public:
	static const int MAX_PATIENT_SIZE = 20;

public:
	OfficeStaff(const Person & person, long extension, long salary, Room & room) : Staff(person, extension, salary, room) {};

	// Show
	void OfficeStaff::toOs(ostream & os) const override;
};

#endif // !__OFFICESTAFF_H
