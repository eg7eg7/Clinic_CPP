#include "Patient.h"

Patient::Patient(const Person & person, Doctor& personalDoctor) : Person(person)
{
	numTurns = 0;
	turns = new Turn*[MAX_TURNS_SIZE];
	for (int i = 0; i < MAX_TURNS_SIZE; i++)
		turns[i] = nullptr;
	//this->clinicMember = clinicMember;
	this->personalDoctor = &personalDoctor;
}

Patient::Patient(Patient & other) : Person(other)
{
	numTurns = other.numTurns;
	turns = new Turn*[MAX_TURNS_SIZE];
	for (int i = 0; i < MAX_TURNS_SIZE; i++)
		turns[i] = other.turns[i];
	//this->clinicMember = other.clinicMember;
	this->personalDoctor = other.personalDoctor;
}

Patient::~Patient()
{
	delete[]turns;
}

void Patient::operator=(const Patient & patient)
{
	//TODO
}

int Patient::answerCall()
{
	int ans;
	cin >> ans;
	return ans;
}

void Patient::changeDoctor(Doctor& doctor)
{
	personalDoctor = &doctor;
}

void Patient::changeClinicMember(bool clinicMember)
{
	//this->clinicMember = clinicMember;
}

void Patient::addTurn(Turn & turn)
{
	if (numTurns < MAX_TURNS_SIZE)
	{
		for (int i = 0; i < MAX_TURNS_SIZE; i++)
		{
			if (turns[i] == nullptr)
			{
				turns[i] = &turn;
				++numTurns;
				break;
			}
		}
	}
}

void Patient::deleteTurn(Turn & turn)
{

	for (int i = 0; i < MAX_TURNS_SIZE; i++)
	{
		if (turns[i] == &turn)
		{
			turns[i] = nullptr;
			--numTurns;
			break;
		}
	}
}

void Patient::toOs(ostream & os) const
{

	os << "**Patient**" << endl;
	Person::toOs(os);
	os << " Personal doctor is " << this->personalDoctor->getName() << endl;

}

