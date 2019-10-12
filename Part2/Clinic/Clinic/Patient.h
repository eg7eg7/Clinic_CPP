#pragma message("Adding Patient")
#ifndef __PATIENT_H
#define __PATIENT_H

#pragma warning(disable: 4996)

#include <iostream>
using namespace std;
#include "Doctor.h"

class Patient : public Person
{
public:
	static const int MAX_TURNS_SIZE = 20;
protected:

	Turn** turns;
	Doctor* personalDoctor;
	int numTurns;
	bool isSick;
public:
	Patient(const Person& person, Doctor& personalDoctor, bool sick = false); // Constructor
	Patient(Patient&& other); //move ctor
	Patient(Patient& other); // copy constructor
	virtual ~Patient();

	const Patient& operator=(const Patient& other);

	// Methods

	/* Returns true if sick and needs a turn*/
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

	bool getIsSick() const { return isSick; };
	void setIsSick(const bool sick) { isSick = sick; };
};

#endif // !__PATIENT_H
