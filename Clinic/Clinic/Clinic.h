#ifndef __CLINIC_H
#define __CLINIC_H

#include "Room.h"
#include "Patient.h"
#include "Staff.h"
#include "Address.h"

const int Clinc_SIZE = 20;

class Clinic
{

private:
	
	char* name;
	Address address;
	Room** rooms;
	int roomNumber;
	Staff** staffs;
	int staffNumber;
	Patient** patients;
	int patientNumber;




public:
	Clinic(const char* name ,const Address& address);
	Clinic(const Clinic& other); // copy constructor
	~Clinic();
	
	void operator=(const Clinic& clinic);

	// Methods
	void addStaff(const Staff& staff);
	void removeStaff(const Staff& staff);

	void addPatient(const Patient& patient);
	void removePatient(const Patient& patient);
	void callPatient(const Patient& patient);

	void addRoom(const Room& room);
	void removeRoom(const Room& room);

	void addTurn(const Turn& turn);
	void deleteTurn(const Turn& turn);
	void updateTurn(const Turn& oldturn, const Turn& newturn);

	
	// Show
	void printStaffs() const;
	void printPatients() const;
	void printRooms() const;
	void printTurns() const;

};


#endif // !__CLINIC_H
