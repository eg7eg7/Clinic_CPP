#include "OfficeStaff.h"

OfficeStaff::OfficeStaff(const Staff & staff, Room & roomm) : Staff(staff)
{
	//if (!room.isOccupied())
	//{
	roomm.setOccupied(true);
	room = &roomm;
	//this->room->setOccupied(true);

	//}
	//else
	//	this->room = nullptr;

	//this->patientNumber = 0;
	//patients = new Patient*[MAX_PATIENT_SIZE];
	//for (int i = 0; i < MAX_PATIENT_SIZE; i++)
		//patients[i] = nullptr;
}

OfficeStaff::OfficeStaff(const OfficeStaff & other) : Staff(other)
{
	room = other.room;
	//this->patientNumber = other.patientNumber;
	//patients = new Patient*[MAX_PATIENT_SIZE];
	//for (int i = 0; i < MAX_PATIENT_SIZE; i++)
	//{
	//	patients[i] = other.patients[i];
	//}
}

OfficeStaff::OfficeStaff(OfficeStaff && other) : Staff(other)
{
	room = other.room;
	other.room = nullptr;
}

OfficeStaff::~OfficeStaff()
{
	//if (room != nullptr)
	room->setOccupied(false);
	//delete[]patients;
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
	os << "is located at " << *room;
}
