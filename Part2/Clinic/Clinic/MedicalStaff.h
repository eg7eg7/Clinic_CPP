#pragma message("Adding MedicalStaff")
#ifndef __MEDICALSTAFF_H
#define __MEDICALSTAFF_H
#pragma warning(disable: 4996)
#include "Time.h"
#include <iostream>
#include "Staff.h"

using namespace std;
class Turn;

class MedicalStaff : virtual public Staff
{
public:
	static const int TURN_SIZE = 20;
protected:

	Time acceptHoursFrom;
	Time acceptHoursTo;
	Room* room;

	mutable Turn** turns;
	mutable int turnsNumber;

public:
	MedicalStaff(const Person& person, long extension, long salary, Time acceptHoursFrom, Time acceptHoursTo, Room& room);
	MedicalStaff(const MedicalStaff& other); // copy constructor
	MedicalStaff(MedicalStaff&& other); // move constructor
	virtual ~MedicalStaff();

	const MedicalStaff& operator=(const MedicalStaff& medicalstaff);

	// Methods

	/* Returns time where the medical staff has enough time for an appointment */
	Time getNextFreeTime(long sessionDurationMins) const;
	void addTurn(Turn& turn);
	void deleteTurn(const Turn& turn);
	
	Turn* operator[](int index);
	// Show
	virtual void toOs(ostream& os) const override;
};

#endif // !__MEDICALSTAFF_H
