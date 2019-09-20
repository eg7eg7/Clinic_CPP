#ifndef __TURN_H
#define __TURN_H

#include "MedicalStaff.h"
#include "Patient.h"
#include "Staff.h"


class Turn
{

private:

	long startTime;
	long duration;
	MedicalStaff medicalStaff;
	Patient patient;


public:
	Turn(const Staff& medicalStaff ,const Patient& patient ,long startTime ,long duration);	// Constructor
	Turn(const Turn& other); //  copy constructor
	~Turn();

	void operator=(const Turn& turn);

	// Methods
	void changeStartTime(long startTime);
	void changeDuration(long duraction);
	void changeMedicalStaff(const MedicalStaff& medicalStaff);
	void changePatient(const Patient& patient);


	// Show
	void print() const;


};



#endif // !__TURN_H
