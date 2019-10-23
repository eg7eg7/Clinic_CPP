#ifndef __CLINIC_H
#define __CLINIC_H
#pragma warning(disable: 4996)
#pragma warning(disable: 4290)
#include <iostream>
#include <string.h>
#include "ClinicManager.h"
#include "Secretary.h"
#include "Nurse.h"
using namespace std;

class ClinicManager;

class Clinic
{
	friend class ClinicManager;
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

	~Clinic();

	const Clinic& operator=(const Clinic& clinic);

	// Methods

	void addPatient(Patient * patient);
	void removePatient(const Patient& patient);

	void addRoom(Room* room);
	void removeRoom(const Room& room);

	void addTurn(Turn& turn);
	void removeTurn(const Turn& turn);

	const char* getName() const { return name; };
	const Address& getAddress() const { return address; };
	const ClinicManager* getManager() const { return manager; };

	void checkPatients();

	void setClinicManager(ClinicManager* new_manager);

	void setAddress(const Address& address);

	Secretary& getSecretary() const throw (const char*);
	Nurse& getNurse() const throw (const char*);

	// Show
	void printStaff(ostream & os) const;
	void printPatients(ostream & os) const;
	void printRooms(ostream & os) const;
	void printTurns(ostream & os) const;

	friend ostream & operator<<(ostream & os, const Clinic & clinic);

private:
	void addStaff(Staff * staff);
	void removeStaff(Staff& staff);
	void setName(const char* newName);

	Turn** getTurns() const { return turns; }
	Staff** getStaff() const { return staff; }
	Patient** getPatients() const { return patients; }
	Room** getRooms() const { return rooms; }
};

#endif // !__CLINIC_H
