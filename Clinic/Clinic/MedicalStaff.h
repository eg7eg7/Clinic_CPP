#ifndef __MEDICALSTAFF_H
#define __MEDICALSTAFF_H

#include "Staff.h"
#include "Room.h"
#include "Turn.h"

const int TURN_SIZE = 20;

class MedicalStaff : virtual public Staff
{

private:

	long acceptHourseFrom;
	long acceptHourseTo;
	Room room;
	Turn** turns;
	int turnsNumber;



public:
	MedicalStaff(const Person& person, long extention, long salary, long acceptHourseFrom, long acceptHourseTo, const Room& room) 
		: Staff(person, extention, salary) { 
		//TODO 
	}; // Constructor
	MedicalStaff(const MedicalStaff& other) : Staff(other) {
	//TODO
	}; // copy constructor
	~MedicalStaff();

	void operator=(const MedicalStaff& medicalstaff);

	// Methods
	long getNextFreeTime() const;
	void addTurn(const Turn& turn);
	void deleteTurn(const Turn& turn);
	void updateTurn(const Turn& turn, int index);

	// Show
	void print() const;


};


#endif // !__MEDICALSTAFF_H
