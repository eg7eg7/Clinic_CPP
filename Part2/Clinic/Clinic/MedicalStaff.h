#ifndef __MEDICALSTAFF_H
#define __MEDICALSTAFF_H
#pragma warning(disable: 4996)

#include <iostream>
#include "Staff.h"
#include "Room.h"

using namespace std;
class Turn;
const int TURN_SIZE = 20;

class MedicalStaff : virtual public Staff
{
private:

	long acceptHoursFrom;
	long acceptHoursTo;
	Room* room;
	//Turn** turns;
	//int turnsNumber;

public:
	MedicalStaff(const Person& person, long extension, long salary, long acceptHoursFrom, long acceptHoursTo, Room& room);
	MedicalStaff(const MedicalStaff& other); // copy constructor
	virtual ~MedicalStaff();

	void operator=(const MedicalStaff& medicalstaff);

	// Methods
	long getNextFreeTime() const { //TODO
	};
	//void addTurn(Turn& turn);
	//void deleteTurn(const Turn& turn);

	//Turn* operator[](int index);
	// Show
	//friend ostream & operator<<(ostream & os, const MedicalStaff & staff);
	virtual void toOs(ostream& os) const;
};

#endif // !__MEDICALSTAFF_H
