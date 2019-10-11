#pragma message("Adding OfficeStaff")
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
protected:

	//Patient** patients;
	//int patientNumber;

public:
	OfficeStaff(const Person & person, long extension, long salary, Room & room) : Staff(person, extension, salary, room) {};
	OfficeStaff(const Staff& staff); // Constructor
	OfficeStaff(const OfficeStaff& other); // copy constructor
	OfficeStaff(OfficeStaff&& other); // move constructor
	virtual ~OfficeStaff();

	//void operator=(const OfficeStaff& officestaff);

	// Methods
	//void addPatient(Patient& patient);
	//void removePatient(const Patient& patient);

	// Show
	void OfficeStaff::toOs(ostream & os) const override;
};

#endif // !__OFFICESTAFF_H
