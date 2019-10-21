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
	int timeDifference1 = 0;
	int timeDifference2 = 0;
	if (turns.size() != 0)
	{
		timeDifference1 = Time::getTimeDifference(this->acceptHoursFrom, turns[0]->getStartTime());
		if (timeDifference1 >= sessionDurationMins)
			return this->acceptHoursTo;
	}
	else
		return this->acceptHoursFrom;

	for (int i = 0; i < turns.size() - 1; i++)
	{
		//check if doctor has a time gap for desired duration
		timeDifference1 = Time::getTimeDifference(turns[i]->getEndTime(), turns[i + 1]->getStartTime());
		timeDifference2 = Time::getTimeDifference(turns[i]->getEndTime(), this->acceptHoursTo);

		if (timeDifference1 >= sessionDurationMins && timeDifference2 >= sessionDurationMins)
		{
			return turns[i]->getEndTime();
		}


	}
	timeDifference1 = Time::getTimeDifference(turns[turns.size() - 1]->getEndTime(), this->acceptHoursTo);
	if (timeDifference1 >= sessionDurationMins)
		return turns[turns.size() - 1]->getEndTime();

	Time t = Time();
	return t;
}

void MedicalStaff::addTurn(Turn& turn) const
{
	if (turns.size() < TURN_SIZE)
	{
		turns.add(&turn);
	}
	turns.sort(ComparePointer());
}

void MedicalStaff::deleteTurn(Turn& turn) const
{
	turns.remove(&turn);
	turns.sort(ComparePointer());
}

Turn * MedicalStaff::operator[](int index)
{
	return turns[index];
}

void MedicalStaff::toOs(ostream & os) const
{
	os << "**Medical Staff**" << endl;
	Staff::toOs(os);
	os << " Accepting from " << acceptHoursFrom << " to " <<
		acceptHoursTo << endl;
}