#pragma message("Adding Turn")
#ifndef __TURN_H
#define __TURN_H

#pragma warning(disable: 4996)
#include "Time.h"
#include <iostream>
using namespace std;
#include "Patient.h"
class MedicalStaff;
class Patient;

class Turn
{
protected:
	
	long sessionDurationMins;

	Time startTime;
	MedicalStaff* medicalStaff;
	Patient* patient;
private:
	Turn(Turn&& other); //  move constructor
	
public:
	
	Turn(MedicalStaff& medicalStaff, Patient& patient, Time startTime, long sessionDurationMins);	// Constructor
	Turn(const Turn& other); //  copy constructor
	
	virtual ~Turn() {};

	//void operator=(const Turn& turn);

	// Methods
	static void sortTurns(Turn** turns, int size);
	const Time getStartTime() const { return startTime; };
	const long getDurationMins() const { return sessionDurationMins; };
	Time getEndTime() const;
	MedicalStaff* getMedicalStaff() const { return medicalStaff; };
	const Patient* getPatient() const { return patient; };

	void changeStartTime(Time startTime);
	void changeDuration(long sessionDurationMins);
	void changeMedicalStaff(MedicalStaff* medicalStaff);
	void changePatient(Patient* patient);

	// Show
	friend ostream & operator<<(ostream & os, const Turn & turn);
	const Turn& operator=(const Turn& other);
};

#endif // !__TURN_H
