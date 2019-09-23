#ifndef __CLINICMANAGER_H
#define __CLINICMANAGER_H
#pragma message("Adding ClinicManager")
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#include "OfficeStaff.h"
#include "Clinic.h"
#include "Doctor.h"
const int STAFF_SIZE = 20;

class Clinic;

class ClinicManager : public OfficeStaff, public Doctor
{
private:
	Clinic* clinic;

public:
	ClinicManager(const OfficeStaff& officeStaff, const Doctor& doctor) : Staff(officeStaff), OfficeStaff(officeStaff), Doctor(doctor) {}; // Constructor
	ClinicManager(const ClinicManager& other) : Staff(other), OfficeStaff(other), Doctor(other) { this->clinic = other.clinic; }; // copy constructor
	virtual ~ClinicManager() {};

	//void operator=(const ClinicManager& clinicmanager);

	void setClinic(Clinic* new_clinic);

	// Method
	void fireStaff(const Staff& staff);
	void hireStaff(const Staff& staff);
};

#endif // !__CLINICMANAGER_H
