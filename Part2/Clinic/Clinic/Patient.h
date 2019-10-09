#ifndef __PATIENT_H
#define __PATIENT_H

#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#include "Person.h"
#include "Doctor.h"


class Doctor;
class Turn;

class Patient : public Person
{
public:
	static const int MAX_TURNS_SIZE = 20;
protected:

	Turn** turns;
	Doctor* personalDoctor;
	int numTurns;

public:
	Patient(const Person& person, Doctor& personalDoctor); // Constructor
	Patient(Patient& other); // copy constructor
	virtual ~Patient();

	void operator=(const Patient& patient);

	// Methods
	int answerCall();
	void changeDoctor(Doctor & doctor);
	void changeClinicMember(bool clinicMember);
	int getNumTurns() { return numTurns; };

	void addTurn(Turn & turn);
	void deleteTurn(Turn & turn);
	// Show
	void toOs(ostream & os) const override;

	Doctor* getPersonalDoctor() const { return personalDoctor; };
	void setPersonalDoctor(Doctor & doctor) { personalDoctor = &doctor; }
};

#endif // !__PATIENT_H
