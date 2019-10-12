#include "ClinicManager.h"

ClinicManager::ClinicManager(const OfficeStaff && officeStaff, const Doctor && doctor) : Staff(std::move(officeStaff)), OfficeStaff(std::move(officeStaff)), Doctor(std::move(doctor))
{
	//nothing
}

const ClinicManager & ClinicManager::operator=(const ClinicManager & other)
{
	if (this != &other)
	{
		Doctor::operator=(other);
		OfficeStaff::operator=(other);
		//nothing
	}
	return *this;
}

void ClinicManager::setClinic(Clinic* new_clinic)
{
	if (clinic != new_clinic)
	{
		clinic = new_clinic;
		if (clinic != nullptr)
			clinic->setClinicManager(this);
	}
}

void ClinicManager::fireStaff(Staff & staff) const
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
		clinic->addStaff(&staff);
	}
}

void ClinicManager::toOs(ostream & os) const
{
	os << "**ClinicManager**" << endl;
	os << "**OfficeStaff**" << endl;
	Doctor::toOs(os);
}