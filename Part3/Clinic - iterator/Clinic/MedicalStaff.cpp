#include "MedicalStaff.h"
#include "Turn.h"

MedicalStaff::MedicalStaff(const Person& person, long extension, long salary, Time acceptHoursF, Time acceptHoursT, Room& room)
	: Staff(person, extension, salary, room), turns()
{
	acceptHoursFrom = acceptHoursF;
	acceptHoursTo = acceptHoursT;
}

MedicalStaff::MedicalStaff(const MedicalStaff& other) : Staff(other), turns(other.turns)
{
	*this = other;
}

MedicalStaff::MedicalStaff(MedicalStaff && other) : Staff(std::move(other)), turns(std::move(turns))
{
	acceptHoursFrom = std::move(other.acceptHoursFrom);
	acceptHoursTo = std::move(other.acceptHoursTo);
}

MedicalStaff::~MedicalStaff()
{
	//nothing
}

const MedicalStaff& MedicalStaff::operator=(const MedicalStaff& medicalstaff)
{
	if (this != &medicalstaff)
	{
		Staff::operator=(medicalstaff);

		acceptHoursFrom = medicalstaff.acceptHoursFrom;
		acceptHoursTo = medicalstaff.acceptHoursTo;
		turns = medicalstaff.turns;
	}
	return *this;
}

Time MedicalStaff::getNextFreeTime(long sessionDurationMins) const
{
	cout << "getNextFreeTime" << endl;
	Turn* t = nullptr;
	Turn* t2 = nullptr;
	int timeDifference1 = 0;
	int timeDifference2 = 0;
	if (turns.size() != 0)
	{
		cout << "trying to get turn 0" << endl;
		t = (*(turns[0]));
		if (t != nullptr)
			timeDifference1 = Time::getTimeDifference(this->acceptHoursFrom, t->getStartTime());
		else
			cout << "NULL HERE" << endl;
		if (timeDifference1 >= sessionDurationMins)
			return this->acceptHoursTo;
	}
	else
		return this->acceptHoursFrom;

	for (int i = 0; i < turns.size() - 1; i++)
	{
		//check if doctor has a time gap for desired duration
		cout << "trying to get turn " << i << endl;
		t = (*(turns[i]));
		cout << "trying to get turn " << i+1 << endl;
		t2 = (*(turns[i + 1]));
		if (t != nullptr && t2 !=nullptr)
			timeDifference1 = Time::getTimeDifference(t->getEndTime(), (*turns[i + 1])->getStartTime());
		else
			cout << "NULL HERE" << endl;
		if (t != nullptr && t2 != nullptr)
			timeDifference2 = Time::getTimeDifference(t->getEndTime(), this->acceptHoursTo);
		else
			cout << "NULL HERE" << endl;
		if (timeDifference1 >= sessionDurationMins && timeDifference2 >= sessionDurationMins)
		{
			return t->getEndTime();
		}
	}
	t = (*turns[turns.size() - 1]);
	if (t != nullptr)
		timeDifference1 = Time::getTimeDifference(t->getEndTime(), this->acceptHoursTo);
	else
		cout << "NULL HERE" << endl;
	if (timeDifference1 >= sessionDurationMins)
		return (*turns[turns.size() - 1])->getEndTime();
	else
		cout << "NULL HERE" << endl;
	Time time = Time();
	return time;
}

void MedicalStaff::addTurn(Turn& turn) const
{
	if (turns.size() < TURN_SIZE)
	{
		turns.add(&turn);
	}
	//turns.sort(ComparePointer());
}

void MedicalStaff::deleteTurn(Turn& turn) const
{
	turns.remove(&turn);
	//turns.sort(ComparePointer());
}

Turn * MedicalStaff::operator[](int index)
{
	return *(turns[index]);
}

void MedicalStaff::toOs(ostream & os) const
{
	os << "**Medical Staff**" << endl;
	Staff::toOs(os);
	os << " Accepting from " << acceptHoursFrom << " to " <<
		acceptHoursTo << endl;
}