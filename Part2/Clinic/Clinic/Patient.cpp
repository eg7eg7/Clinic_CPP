#include "Patient.h"

Patient::Patient(const Person & person, Doctor& personalDoctor, bool sick) : Person(person)
{
	numTurns = 0;
	turns = new Turn*[MAX_TURNS_SIZE];
	for (int i = 0; i < MAX_TURNS_SIZE; i++)
		turns[i] = nullptr;
	//this->clinicMember = clinicMember;
	this->personalDoctor = &personalDoctor;
	isSick = false;
}

Patient::Patient(Patient && other) : Person(std::move(other))
{
	numTurns = other.numTurns;
	turns = std::move(other.turns);
	
	//this->clinicMember = other.clinicMember;
	this->personalDoctor = std::move(other.personalDoctor);
	isSick = other.isSick;
}

Patient::Patient(Patient & other) : Person(other)
{
	*this = other;
}

Patient::~Patient()
{
	delete[]turns;
}

const Patient & Patient::operator=(const Patient & other)
{
	if (this != &other)
	{
		Person::operator=(other);
		delete[]turns;
		numTurns = other.numTurns;
		turns = new Turn*[MAX_TURNS_SIZE];
		for (int i = 0; i < MAX_TURNS_SIZE; i++)
			turns[i] = other.turns[i];
		//this->clinicMember = other.clinicMember;
		this->personalDoctor = other.personalDoctor;
		isSick = other.isSick;
	}
	return *this;
}

int Patient::answerCall()
{
	return isSick;
}

void Patient::changeDoctor(Doctor& doctor)
{
	personalDoctor = &doctor;
}

void Patient::changeClinicMember(bool clinicMember)
{
	//TODO remove func
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