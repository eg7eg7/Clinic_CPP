#ifndef __TURN_H
#define __TURN_H
#pragma message("Adding Turn")

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
	//TODO add flag for turn - was it used or not

public:
	Turn(MedicalStaff& medicalStaff, Patient& patient, long startTime, long duration);	// Constructor
	Turn(const Turn& other); //  copy constructor
	virtual ~Turn() {};

	//void operator=(const Turn& turn);

	// Methods
	void changeStartTime(long startTime);
	void changeDuration(long duration);
	void changeMedicalStaff(MedicalStaff* medicalStaff);
	void changePatient(Patient* patient);

	// Show
	void print() const;
};

#endif // !__TURN_H
