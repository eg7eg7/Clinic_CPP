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
	friend class secretary;
protected:

	long sessionDurationMins;

	Time startTime;
	MedicalStaff* medicalStaff;
	Patient* patient;
private:
	Turn(Turn&& other); //  move constructor

	void setStartTime(const Time& time);
	void setDurationsMins(const int& time);
public:

	Turn(MedicalStaff& medicalStaff, Patient& patient, Time startTime, long sessionDurationMins);	// Constructor
	Turn(const Turn& other) = delete; //  copy constructor

	// Methods
	static void sortTurns(Turn** turns, const int& size);
	const Time& getStartTime() const { return startTime; };
	const long& getDurationMins() const { return sessionDurationMins; };

	/* calculated end time */
	Time getEndTime() const;

	const MedicalStaff* getMedicalStaff() const { return medicalStaff; };
	const Patient* getPatient() const { return patient; };

	void changeStartTime(const Time& startTime);
	void changeDuration(const long& sessionDurationMins);
	void changeMedicalStaff(MedicalStaff* medicalStaff);
	void changePatient(Patient* patient);

	// Show
	friend ostream & operator<<(ostream & os, const Turn & turn);
};

#endif // !__TURN_H
