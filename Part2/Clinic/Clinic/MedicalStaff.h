#ifndef __MEDICALSTAFF_H
#define __MEDICALSTAFF_H
#pragma warning(disable: 4996)

#include <iostream>
#include "Staff.h"
#include "Room.h"

using namespace std;
class Turn;


class MedicalStaff : virtual public Staff
{
public:
	static const int TURN_SIZE = 20;
protected:

	long acceptHoursFrom;
	long acceptHoursTo;
	Room* room;

	mutable Turn** turns;
	mutable int turnsNumber;

public:
	MedicalStaff(const Person& person, long extension, long salary, long acceptHoursFrom, long acceptHoursTo, Room& room);
	MedicalStaff(const MedicalStaff& other); // copy constructor
	virtual ~MedicalStaff();

	void operator=(const MedicalStaff& medicalstaff);

	// Methods

	/* Returns time where the medical staff has enough time */
	long getNextFreeTime(long duration) const { 
		
		//TODO
		return 0;
	};
	void addTurn(Turn& turn) const;
	void deleteTurn(const Turn& turn);

	Turn* operator[](int index);
	// Show
	virtual void toOs(ostream& os) const override;
};

#endif // !__MEDICALSTAFF_H
