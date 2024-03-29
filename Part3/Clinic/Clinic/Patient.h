#ifndef __PATIENT_H
#define __PATIENT_H

#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
using namespace std;

#include "ClinicObserver.h"
#include "Doctor.h"
class Patient : public Person, public ClinicObserver
{
public:
	static const int MAX_TURNS_SIZE = 20;
	enum eStatus { HEALTHY, SICK, REQUIRE_TREATMENT };
	static const string eStatusString[];

protected:

	mutable vector<Turn*> turns;
	Doctor* personalDoctor;
	eStatus status;
public:
	Patient(const Person& person, Doctor& personalDoctor, eStatus status = HEALTHY); // Constructor
	// Methods

	/* Returns true if sick and needs a turn*/
	const eStatus& answerCall() const;

	void changeDoctor(Doctor & doctor);
	int getNumTurns() { return (int)turns.size(); };

	void addTurn(Turn & turn) const;
	void deleteTurn(Turn & turn) const;
	// Show
	void toOs(ostream & os) const override;

	Doctor* getPersonalDoctor() const { return personalDoctor; };
	void setPersonalDoctor(Doctor & doctor) { personalDoctor = &doctor; }

	const eStatus& getIsSick() const { return status; };
	void setIsSick(const eStatus sick) { status = sick; };

	void notify(Turn * turn) const override;
};

#endif // !__PATIENT_H
