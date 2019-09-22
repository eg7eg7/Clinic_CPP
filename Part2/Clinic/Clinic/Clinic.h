#ifndef __CLINIC_H
#define __CLINIC_H
#pragma warning(disable: 4996)
#include <iostream>
#include <string.h>
#include "Address.h"
#include "ClinicManager.h"
#include "Room.h"
#include "Patient.h"
#include "Staff.h"


using namespace std;

const int MAX_NUM_ROOMS = 20;
const int MAX_NUM_STAFF = 50;
const int MAX_NUM_PATIENTS = 1000;
const int MAX_NUM_TURNS = 500;

class ClinicManager;

class Clinic
{

private:
	
	char* name;
	Address address;
	Room** rooms;
	int numRooms;
	Staff** staff;
	int numStaff;
	Patient** patients;
	int numPatients;
	Turn** turns;
	int numTurns;

	ClinicManager* manager;


public:
	Clinic(const char* name ,const Address& address);
	Clinic(const Clinic& other); // copy constructor
	virtual ~Clinic();
	
	//void operator=(const Clinic& clinic);

	// Methods
	void addStaff(Staff& staff);
	void removeStaff(const Staff& staff);

	void addPatient(Patient& patient);
	void removePatient(const Patient& patient);
	void callPatient(const Patient& patient);

	void addRoom(Room& room);
	void removeRoom(const Room& room);

	void addTurn(Turn& turn);
	void removeTurn(const Turn& turn);
	void updateTurn(const Turn& oldturn, const Turn& newturn);

	
	// Show
	void printStaff() const;
	void printPatients() const;
	void printRooms() const;
	void printTurns() const;

	void setClinicManager(ClinicManager* new_manager);

};


#endif // !__CLINIC_H
