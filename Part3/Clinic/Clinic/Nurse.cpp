#include "Nurse.h"
#pragma warning(disable: 4996)

Nurse::Nurse(const MedicalStaff& medicalStaff, const string& service) : Staff(medicalStaff), MedicalStaff(medicalStaff) 
{
	numServices = 1;
	services = new string[MAX_NURSE_SERVICES];
	services[0] = service;
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
	delete[]services;
}

const Nurse& Nurse::operator=(const Nurse& nurse)
{
	string* nurseServices;
	if (this != &nurse)
	{
		MedicalStaff::operator=(nurse);
		nurseServices = nurse.getServices();
		numServices = nurse.getNumServices();
		for (int i = 0; i < numServices; i++)
		{
			services[i] = nurseServices[i];
		}
	}
	return *this;
}

void Nurse::addServices(const string& service)
{
	if (numServices <= MAX_NURSE_SERVICES)
	{
		services[numServices] = service;
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