#ifndef __CLINICMANAGER_H
#define __CLINICMANAGER_H


#include "OfficeStaff.h"
#include "Staff.h"

const int STAFF_SIZE = 20;


class ClinicManager : public OfficeStaff
{

private:
	Staff** staff;
	int staffSize;

public:
	ClinicManager(const OfficeStaff& officeStaff); // Constructor
	ClinicManager(const ClinicManager& other); // copy constructor
	~ClinicManager();

	void operator=(const ClinicManager& clinicmanager);

	// Method
	void fireStaff(const Staff& staff);
	void removeStaff(const Staff& staff);


};

#endif // !__CLINICMANAGER_H
