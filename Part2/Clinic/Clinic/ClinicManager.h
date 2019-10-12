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
	//TODO remove
	static const int STAFF_SIZE = 20;
private:
	
	ClinicManager(const OfficeStaff& officeStaff, const Doctor&& doctor);
	ClinicManager(const OfficeStaff&& officeStaff, const Doctor& doctor);
public:
	ClinicManager(const OfficeStaff&& officeStaff, const Doctor&& doctor);
	ClinicManager(const OfficeStaff& officeStaff, const Doctor& doctor) : Staff(officeStaff), OfficeStaff(officeStaff), Doctor(doctor) {}; // Constructor
	ClinicManager(const ClinicManager& other) : Staff(other), OfficeStaff(other), Doctor(other) { *this = other; }; // copy constructor
	virtual ~ClinicManager() {};

	const ClinicManager& operator=(const ClinicManager& other);

	void setClinic(Clinic* new_clinic);

	// Method
	void fireStaff(Staff& staff) const;
	void hireStaff(Staff& staff) const;

	//show
	void toOs(ostream & os) const override;
};

#endif // !__CLINICMANAGER_H
