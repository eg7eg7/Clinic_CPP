#include "OfficeStaff.h"

OfficeStaff::OfficeStaff(const OfficeStaff & other) : Staff(other)
{
	*this = other;
	
	//this->patientNumber = other.patientNumber;
	//patients = new Patient*[MAX_PATIENT_SIZE];
	//for (int i = 0; i < MAX_PATIENT_SIZE; i++)
	//{
	//	patients[i] = other.patients[i];
	//}
}

OfficeStaff::OfficeStaff(OfficeStaff && other) : Staff(std::move(other))
{
	room = std::move(other.room);
}

OfficeStaff::~OfficeStaff()
{
	if (room != nullptr)
		room->addOccupant();
	//delete[]patients;
}
const OfficeStaff & OfficeStaff::operator=(const OfficeStaff & other)
{
	if (this != &other)
	{
		Staff::operator=(other);
		room = other.room;
	}
	return *this;
}
/*
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

*/
void OfficeStaff::toOs(ostream & os) const
{
	os << "**OfficeStaff**" << endl;
	Staff::toOs(os);
}