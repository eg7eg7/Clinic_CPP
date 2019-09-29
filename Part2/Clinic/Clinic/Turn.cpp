#include "Turn.h"

Turn::Turn(MedicalStaff& medicalStaff, Patient& patient, long startTime, long duration)
{
	this->medicalStaff = &medicalStaff;
	this->patient = &patient;

	this->startTime = startTime;
	this->duration = duration;
}

Turn::Turn(const Turn & other)
{
	this->medicalStaff = other.medicalStaff;
	this->patient = other.patient;

	this->startTime = other.startTime;
	this->duration = other.duration;
}

void Turn::changeStartTime(long startTime)
{
	this->startTime = startTime;
}

void Turn::changeDuration(long duration)
{
	this->duration = duration;
}

void Turn::changeMedicalStaff(MedicalStaff* medicalStaff)
{
	this->medicalStaff = medicalStaff;
}

void Turn::changePatient(Patient* patient)
{
	this->patient = patient;
}


ostream & operator<<(ostream & os, const Turn & turn)
{
	os << endl <<"Turn beginning at: " << turn.getStartTime() << endl <<
		"Duration: " << turn.getDuration() << endl << "for patient:" << (turn.getPatient())->getName()
		<< endl << "with medical Staff: " << (turn.getMedicalStaff())->getName();
	return os;
}

