#include "OfficeStaff.h"

OfficeStaff::OfficeStaff(const Staff & staff, Room & room) : Staff(staff), room(room)
{
	this->patientNumber = 0;
	patients = new Patient*[MAX_PATIENT_SIZE];
	for (int i = 0; i < MAX_PATIENT_SIZE; i++)
		patients[i] = nullptr;
}

OfficeStaff::OfficeStaff(const OfficeStaff & other) : Staff(other), room(other.room)
{
	this->patientNumber = other.patientNumber;
	patients = new Patient*[MAX_PATIENT_SIZE];
	for (int i = 0; i < MAX_PATIENT_SIZE; i++)
	{
		patients[i] = other.patients[i];
	}
}

OfficeStaff::~OfficeStaff()
{
	delete[]patients;
}

void OfficeStaff::addPatient(Patient & patient)
{
	if (patientNumber < MAX_PATIENT_SIZE)
	{
		for (int i = 0; i < MAX_PATIENT_SIZE; i++)
		{
			if (patients[i] == nullptr)
			{
				patients[i] = &patient;
				++patientNumber;
				break;
			}
		}
	}
}

void OfficeStaff::removePatient(const Patient & patient)
{
	for (int i = 0; i < MAX_PATIENT_SIZE; i++)
	{
		if (patients[i] == &patient)
		{
			patients[i] = nullptr;
			--patientNumber;
			break;
		}
	}
}

void OfficeStaff::print() const
{
	cout << "in OfficeStaff" << endl;
}