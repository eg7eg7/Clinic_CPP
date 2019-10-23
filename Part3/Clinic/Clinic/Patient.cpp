#include "Patient.h"
const string Patient::eStatusString[] = { "Healthy", "Sick","Needs Treatment" };

Patient::Patient(const Person & person, Doctor& personalDoctor, eStatus status) : Person(person)
{
	turns.reserve(MAX_TURNS_SIZE);
	this->personalDoctor = &personalDoctor;
	this->status = status;
}




const Patient::eStatus& Patient::answerCall() const
{
	if (status)
		cout << this->getName() << ">> I'm not feeling well, i'd like to get checked up." << endl;
	else
		cout << this->getName() << ">> It's ok I'm healthy." << endl;
	return status;
}

void Patient::changeDoctor(Doctor& doctor)
{
	personalDoctor = &doctor;
}

void Patient::addTurn(Turn & turn) const
{
	if (turns.size() < MAX_TURNS_SIZE)
	{
		turns.push_back(&turn);
	}
}

void Patient::deleteTurn(Turn & turn) const
{
	auto iterEnd = turns.end();
	for (auto iter = turns.begin(); iter != iterEnd; ++iter)
	{
		if (*iter == &turn)
		{
			turns.erase(iter);
			break;
		}
	}
}

void Patient::toOs(ostream & os) const
{
	os << "**Patient**" << endl;
	Person::toOs(os);
	os << " Personal doctor is " << this->personalDoctor->getName() << endl;
	os << " Status : " << eStatusString[this->status] << endl;
	os << " Has " << turns.size() << " turns scheduled ahead." << endl;
}