#ifndef __CLINICMANAGER_H
#define __CLINICMANAGER_H
#pragma warning(disable: 4996)

#include <iostream>
using namespace std;
#include "OfficeStaff.h"
#include "Clinic.h"

class ClinicManager : public OfficeStaff, public Doctor
{
private:

	ClinicManager(const OfficeStaff& officeStaff, const Doctor&& doctor) = delete;
	ClinicManager(const OfficeStaff&& officeStaff, const Doctor& doctor) = delete;
public:
	ClinicManager(const OfficeStaff& officeStaff, const Doctor& doctor) : Staff(officeStaff), OfficeStaff(officeStaff), Doctor(doctor) {}; // Constructor

	void setClinic(Clinic* new_clinic);

	// Method
	void fireStaff(Staff& staff) const;
	void hireStaff(Staff& staff) const;
	void changeClinicName(const string& newName) const;
	void changeClinicAddress(const Address& address) const;
	//show
	void toOs(ostream & os) const override;
};

#endif // !__CLINICMANAGER_H
