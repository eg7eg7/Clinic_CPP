#include "MedicalStaff.h"

MedicalStaff::MedicalStaff(const Person& person, long extension, long salary, long acceptHoursF, long acceptHoursT, Room& room)
	: Staff(person, extension, salary)
{
	acceptHoursFrom = acceptHoursF;
	acceptHoursTo = acceptHoursT;
	//if (!room.isOccupied())
	//{
		this->room = &room;
		(this->room)->setOccupied(true);

	//}
	//else
	//	this->room = nullptr;

	//turns = new Turn*[TURN_SIZE];
	//for (int i = 0; i < TURN_SIZE; i++)
	//{
	//	turns[i] = nullptr;
	//}
	//turnsNumber = 0;
}

MedicalStaff::MedicalStaff(const MedicalStaff& other) : Staff(other)
{
	this->room = other.room;
	acceptHoursFrom = other.acceptHoursFrom;
	acceptHoursTo = other.acceptHoursTo;
	//turnsNumber = other.turnsNumber;
	//turns = new Turn*[TURN_SIZE];
	//for (int i = 0; i < turnsNumber; i++)
	//{
	//	turns[i] = other.turns[i];
	//}
}

MedicalStaff::~MedicalStaff()
{
	//if (room != nullptr)
		room->setOccupied(false);
	//delete[]turns;
}

void MedicalStaff::operator=(const MedicalStaff& medicalstaff)
{
	if (this != &medicalstaff)
	{
		acceptHoursFrom = medicalstaff.acceptHoursFrom;
		acceptHoursTo = medicalstaff.acceptHoursTo;
		//turnsNumber = medicalstaff.turnsNumber;
		//turns = new Turn*[TURN_SIZE];
		//for (int i = 0; i < turnsNumber; i++)
		//{
		//	turns[i] = medicalstaff.turns[i];
		//}
	}
}
/*
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
}

Turn* MedicalStaff::operator[](int index)
{
	return turns[index];
}
*/
void MedicalStaff::toOs(ostream & os) const
{
	Staff::toOs(os);
	os << "**Medical Staff**" << endl << "Accepting from " << acceptHoursFrom << " to " <<
		acceptHoursTo << " in room " << *room << endl;
	
}
