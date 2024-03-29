#ifndef __MEDICALSTAFF_H
#define __MEDICALSTAFF_H
#pragma warning(disable: 4996)
#include "Time.h"
#include <iostream>
#include "Staff.h"
#include "LinkedList.h"
#include "ClinicObserver.h"
using namespace std;
class Turn;

class MedicalStaff : virtual public Staff, public ClinicObserver
{
public:
	static const int TURN_SIZE = 20;
protected:

	Time acceptHoursFrom;
	Time acceptHoursTo;
	Room* room;

	mutable LinkedList<Turn*> turns;

public:
	MedicalStaff(const Person& person, long extension, long salary, Time acceptHoursFrom, Time acceptHoursTo, Room& room);

	/* Returns time where the medical staff has enough time for an appointment */
	Time getNextFreeTime(long sessionDurationMins) const throw(const string);

	void addTurn(Turn& turn) const;
	void deleteTurn(Turn& turn) const;

	Turn * operator[](int index);
	virtual void toOs(ostream& os) const override;
	virtual void notify(Turn * turn) const override;
};

#endif // !__MEDICALSTAFF_H
