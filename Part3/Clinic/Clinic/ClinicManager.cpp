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
		cout << "manager " << this->getName() << " is firing staff " << staff.getName() << endl;
		clinic->removeStaff(staff);
	}
}

void ClinicManager::hireStaff(Staff & staff) const
{
	if (clinic != nullptr)
	{
		cout << "manager " << this->getName() << " is hiring a new staff " << staff.getName() << endl;
		clinic->addStaff(&staff);
	}
}

void ClinicManager::changeClinicName(const string& newName) const
{
	if (clinic != nullptr)
	{
		cout << "manager " << this->getName() << " is changing clinic name from " << clinic->getName() << " to " << newName << endl;
		clinic->setName(newName);
	}
}

void ClinicManager::toOs(ostream & os) const
{
	os << "**ClinicManager**" << endl;
	os << "**OfficeStaff**" << endl;
	Doctor::toOs(os);
}