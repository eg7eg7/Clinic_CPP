#ifndef __TURN_H
#define __TURN_H

#pragma warning(disable: 4996)

#include <iostream>
using namespace std;
#include "Patient.h"
#include "MedicalStaff.h"
class MedicalStaff;
class Patient;

class Turn
{
private:

	long startTime;
	long duration;
	MedicalStaff* medicalStaff;
	Patient* patient;

public:
	Turn(MedicalStaff& medicalStaff, Patient& patient, long startTime, long duration);	// Constructor
	Turn(const Turn& other); //  copy constructor
	virtual ~Turn() {};

	//void operator=(const Turn& turn);

	// Methods
	const long getStartTime() const { return startTime; } ;
	const long getDuration() const { return duration; } ;
	const MedicalStaff* getMedicalStaff() const { return medicalStaff; };
	const Patient* getPatient() const { return patient; };

	void changeStartTime(long startTime);
	void changeDuration(long duration);
	void changeMedicalStaff(MedicalStaff* medicalStaff);
	void changePatient(Patient* patient);

	// Show
	friend ostream & operator<<(ostream & os, const Turn & turn);
};

#endif // !__TURN_H
