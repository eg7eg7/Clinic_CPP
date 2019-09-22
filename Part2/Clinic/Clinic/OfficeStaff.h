#ifndef __OFFICESTAFF_H
#define __OFFICESTAFF_H
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#include "Staff.h"
#include "Patient.h"

const int MAX_PATIENT_SIZE = 20;


class OfficeStaff : virtual public Staff
{

private:

	Patient** patients;
	int patientNumber;
	Room& room;

public:
	OfficeStaff(const Staff& staff , Room& room); // Constructor
	OfficeStaff(const OfficeStaff& other); // copy constructor
	~OfficeStaff();


	//void operator=(const OfficeStaff& officestaff);

	// Methods
	void addPatient(Patient& patient);
	void removePatient(const Patient& patient);
	

	// Show
	void print() const;


};


#endif // !__OFFICESTAFF_H
