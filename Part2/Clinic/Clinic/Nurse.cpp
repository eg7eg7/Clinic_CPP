#include "Nurse.h"
#pragma warning(disable: 4996)

Nurse::Nurse(const MedicalStaff& medicalStaff, const char* service) : Staff(medicalStaff), MedicalStaff(medicalStaff) {
	num_services = 1;
	services = new char*[MAX_NURSE_SERVICES];
	services[0] = strdup(service);
};

Nurse::Nurse(const Nurse& other) : Staff(other), MedicalStaff(other), services(NULL)
{
	num_services = other.getNumServices();
	char** otherServices = other.getServices();
	for (int i = 0; i < num_services; i++)
		services[i] = strdup(otherServices[i]);
};

Nurse::~Nurse()
{
	for (int i = 0; i < num_services; i++)
		delete[]services[i];
	delete[]services;
}

const Nurse& Nurse::operator=(const Nurse& nurse)
{
	char** nurseServices;
	if (this != &nurse)
	{
		nurseServices = nurse.getServices();
		num_services = nurse.getNumServices();
		for (int i = 0; i < num_services; i++)
		{
			delete[]services[i];
			services[i] = strdup(nurseServices[i]);
		}
	}
	return *this;
}

void Nurse::addServices(const char* service)
{
	if (num_services <= MAX_NURSE_SERVICES)
	{
		services[num_services] = strdup(service);
		++num_services;
	}
}


void Nurse::toOs(ostream & os) const
{
	os << "**Nurse**" << endl
		<< "Can do the following: ";
	for (int i = 0; i < num_services; i++)
		os << services[i] << endl;
}
