#include "MedicalStaff.h"
#include "Turn.h"

MedicalStaff::MedicalStaff(const Person& person, long extension, long salary, Time acceptHoursF, Time acceptHoursT, Room& room)
	: Staff(person, extension, salary, room)
{
	acceptHoursFrom = acceptHoursF;
	acceptHoursTo = acceptHoursT;

	turns = new Turn*[TURN_SIZE];
	for (int i = 0; i < TURN_SIZE; i++)
	{
		turns[i] = nullptr;
	}
	turnsNumber = 0;
}

MedicalStaff::MedicalStaff(const MedicalStaff& other) : Staff(other)
{
	*this = other;
}

MedicalStaff::MedicalStaff(MedicalStaff && other) : Staff(std::move(other))
{
	acceptHoursFrom = std::move(other.acceptHoursFrom);
	acceptHoursTo = std::move(other.acceptHoursTo);
	turnsNumber = other.turnsNumber;
	turns = std::move(other.turns);
}

MedicalStaff::~MedicalStaff()
{
	delete[]turns;
}

const MedicalStaff& MedicalStaff::operator=(const MedicalStaff& medicalstaff)
{
	if (this != &medicalstaff)
	{
		delete[]turns;
		acceptHoursFrom = medicalstaff.acceptHoursFrom;
		acceptHoursTo = medicalstaff.acceptHoursTo;
		turnsNumber = medicalstaff.turnsNumber;
		turns = new Turn*[TURN_SIZE];
		for (int i = 0; i < TURN_SIZE; i++)
		{
			turns[i] = medicalstaff.turns[i];
		}
	}
	return *this;
}

Time MedicalStaff::getNextFreeTime(long sessionDurationMins) const
{
	int timeDifference1 = 0;
	int timeDifference2 = 0;
	if (turns[0] != nullptr)
	{
		timeDifference1 = Time::getTimeDifference(this->acceptHoursFrom, turns[0]->getStartTime());
		if (timeDifference1 >= sessionDurationMins)
			return this->acceptHoursTo;
	}
	else
		return this->acceptHoursFrom;

	for (int i = 0; i < TURN_SIZE - 1; i++)
	{
		if (turns[i] != nullptr && turns[i + 1] != nullptr)
		{
			//check if doctor has a time gap for desired duration
			timeDifference1 = Time::getTimeDifference(turns[i]->getEndTime(), turns[i + 1]->getStartTime());
			timeDifference2 = Time::getTimeDifference(turns[i]->getEndTime(), this->acceptHoursTo);

			if (timeDifference1 >= sessionDurationMins && timeDifference2 >= sessionDurationMins)
			{
				return turns[i]->getEndTime();
			}
		}
		else if (turns[i] != nullptr && turns[i + 1] == nullptr)
		{
			timeDifference1 = Time::getTimeDifference(turns[i]->getEndTime(), this->acceptHoursTo);
			if (timeDifference1 >= sessionDurationMins)
				return turns[i]->getEndTime();
		}
	}
	Time t = Time();
	return t;
}

void MedicalStaff::addTurn(Turn& turn)
{
	if (turnsNumber < TURN_SIZE)
	{
		for (int i = 0; i < TURN_SIZE; i++)
		{
			if (turns[i] == nullptr)
			{
				turns[i] = &turn;
				++turnsNumber;
				break;
			}
		}
	}
	Turn::sortTurns(turns, TURN_SIZE);
}

void MedicalStaff::deleteTurn(const Turn& turn)
{
	for (int i = 0; i < TURN_SIZE; i++)
	{
		if (turns[i] == &turn)
		{
			turns[i] = nullptr;
			--turnsNumber;
			break;
		}
	}
	Turn::sortTurns(turns, TURN_SIZE);
}

Turn* MedicalStaff::operator[](int index)
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