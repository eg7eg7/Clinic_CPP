#include "Patient.h"

Patient::Patient(const Person & person, Doctor& personalDoctor) : Person(person)
{
	//numTurns = 0;
	//turns = new Turn*[MAX_TURNS_SIZE];
	//for (int i = 0; i < MAX_TURNS_SIZE; i++)
	//	turns[i] = nullptr;
	//this->clinicMember = clinicMember;
	this->personalDoctor = &personalDoctor;
}

Patient::Patient(Patient & other) : Person(other)
{
	//numTurns = other.numTurns;
	//turns = new Turn*[MAX_TURNS_SIZE];
	//for (int i = 0; i < MAX_TURNS_SIZE; i++)
	//	turns[i] = other.turns[i];
	//this->clinicMember = other.clinicMember;
	this->personalDoctor = other.personalDoctor;
}

Patient::~Patient()
{
	//delete[]turns;
}

void Patient::operator=(const Patient & patient)
{
	//TODO
}

void Patient::answerCall()
{
	//TODO
}

void Patient::changeDoctor(Doctor& doctor)
{
	personalDoctor = &doctor;
}

void Patient::changeClinicMember(bool clinicMember)
{
	//this->clinicMember = clinicMember;
}

void Patient::toOs(ostream & os) const
{

	os << "**Patient**" << endl;
	Person::toOs(os);
	os << " Personal doctor is " << this->personalDoctor->getName() << endl;

}

