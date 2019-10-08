#ifndef __PATIENT_H
#define __PATIENT_H

#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#include "Person.h"
#include "Doctor.h"
const int MAX_TURNS_SIZE = 20;

class Doctor;
class Turn;

class Patient : public Person
{
private:

	//Turn** turns;
	Doctor* personalDoctor;
	int numTurns;

public:
	Patient(const Person& person, Doctor& personalDoctor); // Constructor
	Patient(Patient& other); // copy constructor
	virtual ~Patient();

	void operator=(const Patient& patient);

	// Methods
	void answerCall();
	void changeDoctor(Doctor & doctor);
	void changeClinicMember(bool clinicMember);
	//int getNumTurns() { return numTurns; };
	// Show
	void toOs(ostream & os) const override;
};

#endif // !__PATIENT_H
