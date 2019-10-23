#include "Nurse.h"
#pragma warning(disable: 4996)

Nurse::Nurse(const MedicalStaff& medicalStaff, const string& service) : Staff(medicalStaff), MedicalStaff(medicalStaff)
{
	services.reserve(MAX_NURSE_SERVICES);
	services.push_back(service);
};

void Nurse::addServices(const string& service)
{
	if (service.size() <= MAX_NURSE_SERVICES)
	{
		services.push_back(service);
	}
}

void Nurse::toOs(ostream & os) const
{
	os << "**Nurse**" << endl;
	MedicalStaff::toOs(os);
	os << "Can do the following: ";
	vector<string>::const_iterator iter = services.begin();
	vector<string>::const_iterator iterEnd = services.end();

	while (iter != iterEnd)
	{
		os << *iter << endl;
		++iter;
	}
}