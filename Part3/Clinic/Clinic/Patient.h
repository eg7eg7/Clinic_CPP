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
	enum eStatus { HEALTHY, SICK, REQUIRE_TREATMENT };
	static const string eStatusString[];

protected:

	mutable Turn** turns;
	Doctor* personalDoctor;
	mutable int numTurns;
	eStatus status;
public:
	Patient(const Person& person, Doctor& personalDoctor, eStatus status = HEALTHY); // Constructor
	Patient(Patient&& other); //move ctor
	Patient(Patient& other); // copy constructor
	~Patient();

	const Patient& operator=(const Patient& other);

	// Methods

	/* Returns true if sick and needs a turn*/
	const eStatus& answerCall() const;

	void changeDoctor(Doctor & doctor);
	int getNumTurns() { return numTurns; };

	void addTurn(Turn & turn) const;
	void deleteTurn(Turn & turn) const;
	// Show
	void toOs(ostream & os) const override;

	Doctor* getPersonalDoctor() const { return personalDoctor; };
	void setPersonalDoctor(Doctor & doctor) { personalDoctor = &doctor; }

	const eStatus& getIsSick() const { return status; };
	void setIsSick(const eStatus sick) { status = sick; };
};

#endif // !__PATIENT_H
