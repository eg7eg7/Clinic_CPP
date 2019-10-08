#include "ClinicManager.h"

void ClinicManager::setClinic(Clinic* new_clinic)
{
	if (clinic != new_clinic)
	{
		clinic = new_clinic;
		if (clinic != nullptr)
			clinic->setClinicManager(this);
	}
}

void ClinicManager::fireStaff(const Staff & staff) const
{
	if (clinic != nullptr)
	{
		clinic->removeStaff(staff);
	}
}

void ClinicManager::hireStaff(Staff & staff) const
{
	if (clinic != nullptr)
	{
		clinic->addStaff(staff);
	}
}

void ClinicManager::toOs(ostream & os) const
{
	
	os << "**ClinicManager**" << endl;
	os << "**OfficeStaff**" << endl;
	Doctor::toOs(os);
}
