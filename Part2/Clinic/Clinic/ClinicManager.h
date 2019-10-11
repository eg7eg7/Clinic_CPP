#pragma message("Adding ClinicManager")
#ifndef __CLINICMANAGER_H
#define __CLINICMANAGER_H
#pragma warning(disable: 4996)

#include <iostream>
using namespace std;
#include "OfficeStaff.h"
#include "Clinic.h"

class ClinicManager : public OfficeStaff, public Doctor
{
public:
	static const int STAFF_SIZE = 20;

protected:
	Clinic* clinic;
public:
	ClinicManager(const OfficeStaff&& officeStaff, const Doctor&& doctor);
	ClinicManager(const OfficeStaff& officeStaff, const Doctor& doctor) : Staff(officeStaff), OfficeStaff(officeStaff), Doctor(doctor) {}; // Constructor
	ClinicManager(const ClinicManager& other) : Staff(other), OfficeStaff(other), Doctor(other) { this->clinic = other.clinic; }; // copy constructor
	virtual ~ClinicManager() {};

	//void operator=(const ClinicManager& clinicmanager);

	void setClinic(Clinic* new_clinic);

	// Method
	void fireStaff(const Staff& staff) const;
	void hireStaff(Staff& staff) const;

	//show
	void toOs(ostream & os) const override;
};

#endif // !__CLINICMANAGER_H
