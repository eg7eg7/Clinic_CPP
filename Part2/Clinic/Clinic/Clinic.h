#pragma message("Adding Clinic")
#ifndef __CLINIC_H
#define __CLINIC_H
#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "ClinicManager.h"
#include "Secretary.h"
#include "Nurse.h"
using namespace std;

class ClinicManager;
//class Staff;
//class Staff;
class Clinic
{
public:
	static const int MAX_NUM_ROOMS = 20;
	static const int MAX_NUM_STAFF = 50;
	static const int MAX_NUM_PATIENTS = 1000;
	static const int MAX_NUM_TURNS = 500;
	static const int DEFAULT_TURN_LENGTH_MINS = 30;

protected:

	char* name;
	Address address;
	ClinicManager* manager;

	Room** rooms;
	int numRooms;

	Staff** staff;
	int numStaff;

	Patient** patients;
	int numPatients;

	mutable Turn** turns;
	mutable int numTurns;

public:
	Clinic(const char* name, const Address& address);
	Clinic(const Clinic& other); // copy constructor
	Clinic(Clinic&& other); // move constructor

	virtual ~Clinic();

	void addStaff(Staff * staff);

	const Clinic& operator=(const Clinic& clinic);

	// Methods
	void removeStaff(Staff& staff);

	void addPatient(Patient & patient);
	void removePatient(const Patient& patient);
	void checkPatients();
	void getAvailableTurn(const Patient& patient);

	void addRoom(Room& room);
	void removeRoom(const Room& room);
	void addTurn(Turn& turn);
	void removeTurn(const Turn& turn);
	
	void updateTurn(const Turn& oldturn, const Turn& newturn);

	void setStaff(Staff ** old_staff, Staff * new_staff);
	
	const char* getName() const { return name; };
	const Address& getAddress() const { return address; };
	const ClinicManager* getManager() const { return manager; };

	// Show
	void printStaff(ostream & os) const;
	void printPatients(ostream & os) const;
	void printRooms(ostream & os) const;
	void printTurns(ostream & os) const;

	friend ostream & operator<<(ostream & os, const Clinic & clinic);

	void setClinicManager(ClinicManager* new_manager);
	const Secretary& getSecretary() const throw (const char*);
	Nurse& getNurse() const throw (const char*);
};

#endif // !__CLINIC_H
