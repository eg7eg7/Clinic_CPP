#ifndef __CLINIC_H
#define __CLINIC_H
#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
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
	static const int DEFAULT_TURN_LENGTH_MINS = 45;

protected:

	string name;
	Address address;
	ClinicManager* manager;

	vector<Room*> rooms;

	vector<Staff*> staff;

	vector<Patient*> patients;

	mutable vector<Turn*> turns;
private:
	Clinic(const Clinic& other) = delete;
	const Clinic& operator=(const Clinic& clinic) = delete;
	Clinic() : Clinic("Default Clinic Name", Address("default country", "default city", "default street", 1, 1, 1)) {};
	Clinic(const string& name, const Address& address);
	Clinic(Clinic&& other);
public:
	~Clinic();

	static Clinic* getInstance();

	// Methods

	void addPatient(Patient * patient);
	void removePatient(const Patient& patient);

	void addRoom(Room* room);
	void removeRoom(const Room& room);

	void addTurn(Turn& turn);
	void removeTurn(const Turn& turn);

	const string& getName() const { return name; };
	const Address& getAddress() const { return address; };
	ClinicManager* getManager() const { return manager; };

	void checkPatients();

	void setClinicManager(ClinicManager* new_manager);

	

	Secretary& getSecretary() const throw (const string);
	Nurse& getNurse() const throw (const string);

	template <class T>
	void printVector(ostream& os, const vector<T*>& vector) const;

	friend ostream & operator<<(ostream & os, const Clinic & clinic);

private:
	void addStaff(Staff * staff);
	void removeStaff(Staff& staff);
	void setAddress(const Address& address);
	void setName(const string& newName) { name = newName; };
	void reserveVectors();
	const vector<Turn*>& getTurns() const { return turns; }
	const vector<Staff*>& getStaff() const { return staff; }
	const vector<Patient*>& getPatients() const { return patients; }
	const vector<Room*>& getRooms() const { return rooms; }

};

template<class T>
void Clinic::printVector(ostream& os, const vector<T*>& vec) const
{
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		os << **it << endl;
		os << "---------------------------------------------------------" << endl;
	}
}
#endif // !__CLINIC_H
