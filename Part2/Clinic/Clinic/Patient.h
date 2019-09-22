#ifndef __PATIENT_H
#define __PATIENT_H
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#include "Person.h"
#include "Turn.h"
#include "Doctor.h"
const int MAX_TURNS_SIZE = 20;

class Turn;
class Doctor;

class Patient : public Person
{
private:

	Turn** turns;
	bool clinicMember;
	Doctor* personalDoctor;
	int numTurns;

public:
	Patient(const Person& person, Doctor* personalDoctor, bool clinicMember); // Constructor
	Patient(Patient& other); // copy constructor
	virtual ~Patient();

	void operator=(const Patient& patient);

	// Methods
	void answerCall();
	void changeDoctor(Doctor* doctor);
	void changeClinicMember(bool clinicMember);
	int getNumTurns() { return numTurns; };
	// Show
	void print() const;
};

#endif // !__PATIENT_H
