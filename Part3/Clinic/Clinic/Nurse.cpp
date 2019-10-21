#include "Nurse.h"
#pragma warning(disable: 4996)

Nurse::Nurse(const MedicalStaff& medicalStaff, const char* service) : Staff(medicalStaff), MedicalStaff(medicalStaff) {
	if (service != nullptr)
		numServices = 1;
	services = new char*[MAX_NURSE_SERVICES];
	services[0] = strdup(service);
};

Nurse::Nurse(const Nurse& other) : Staff(other), MedicalStaff(other)
{
	*this = other;
}
Nurse::Nurse(Nurse && other) : Staff(std::move(other)), MedicalStaff(std::move(other))
{
	services = std::move(other.services);
	numServices = std::move(other.numServices);
}

Nurse::~Nurse()
{
	for (int i = 0; i < numServices; i++)
		delete[]services[i];
	delete[]services;
}

const Nurse& Nurse::operator=(const Nurse& nurse)
{
	char** nurseServices;
	if (this != &nurse)
	{
		MedicalStaff::operator=(nurse);
		nurseServices = nurse.getServices();
		numServices = nurse.getNumServices();
		for (int i = 0; i < numServices; i++)
		{
			delete[]services[i];
			services[i] = strdup(nurseServices[i]);
		}
	}
	return *this;
}

void Nurse::addServices(const char* service)
{
	if (numServices <= MAX_NURSE_SERVICES)
	{
		services[numServices] = strdup(service);
		++numServices;
	}
}

void Nurse::toOs(ostream & os) const
{
	os << "**Nurse**" << endl;
	MedicalStaff::toOs(os);
	os << "Can do the following: ";
	for (int i = 0; i < numServices; i++)
		os << services[i] << endl;
}