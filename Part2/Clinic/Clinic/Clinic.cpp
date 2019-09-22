#include "Clinic.h"

Clinic::Clinic(const char * name, const Address & address) : address(address)
{
	this->name = strdup(name);
	numRooms = 0;
	numStaff = 0;
	numPatients = 0;
	numTurns = 0;
	manager = nullptr;
	rooms = new Room*[MAX_NUM_ROOMS];
	staff = new Staff*[MAX_NUM_STAFF];
	patients = new Patient*[MAX_NUM_PATIENTS];
	turns = new Turn*[MAX_NUM_TURNS];
	for (int i = 0; i < MAX_NUM_ROOMS; i++)
		rooms[i] = nullptr;
	for (int i = 0; i < MAX_NUM_STAFF; i++)
		staff[i] = nullptr;
	for (int i = 0; i < MAX_NUM_PATIENTS; i++)
		patients[i] = nullptr;
	for (int i = 0; i < MAX_NUM_TURNS; i++)
		turns[i] = nullptr;
}

Clinic::Clinic(const Clinic & other) : address(other.address)
{
	this->name = strdup(other.name);
	numRooms = other.numRooms;
	numStaff = other.numStaff;
	numPatients = other.numPatients;
	numTurns = other.numTurns;
	manager = other.manager;
	rooms = new Room*[MAX_NUM_ROOMS];
	staff = new Staff*[MAX_NUM_STAFF];
	patients = new Patient*[MAX_NUM_PATIENTS];
	turns = new Turn*[MAX_NUM_TURNS];

	for (int i = 0; i < MAX_NUM_ROOMS; i++)
		rooms[i] = other.rooms[i];
	for (int i = 0; i < MAX_NUM_STAFF; i++)
		staff[i] = other.staff[i];
	for (int i = 0; i < MAX_NUM_PATIENTS; i++)
		patients[i] = other.patients[i];
	for (int i = 0; i < MAX_NUM_TURNS; i++)
		turns[i] = other.turns[i];
}

Clinic::~Clinic()
{
	setClinicManager(nullptr);
	delete[]name;
	delete[]rooms;
	delete[]staff;
	delete[]patients;
	delete[]turns;
}

void Clinic::addStaff(Staff & staff)
{
	if (numStaff < MAX_NUM_STAFF)
	{
		for (int i = 0; i < MAX_NUM_STAFF; i++)
		{
			if (this->staff[i] == nullptr)
			{
				this->staff[i] = &staff;
			}
		}
		++numStaff;
	}
}

void Clinic::removeStaff(const Staff & staff)
{
	for (int i = 0; i < MAX_NUM_STAFF; i++)
	{
		if (this->staff[i] == &staff)
		{
			this->staff[i] = nullptr;
			--numStaff;
		}
	}
}

void Clinic::addPatient(Patient & patient)
{
	if (numPatients < MAX_NUM_PATIENTS)
	{
		for (int i = 0; i < MAX_NUM_PATIENTS; i++)
		{
			if (this->patients[i] == nullptr)
			{
				this->patients[i] = &patient;
			}
		}
		++numPatients;
	}
}

void Clinic::removePatient(const Patient & patient)
{
	for (int i = 0; i < MAX_NUM_PATIENTS; i++)
	{
		if (patients[i] == &patient)
		{
			patients[i] = nullptr;
			--numPatients;
		}
	}
}

void Clinic::addRoom(Room & room)
{
	if (numRooms < MAX_NUM_ROOMS)
	{
		for (int i = 0; i < MAX_NUM_ROOMS; i++)
		{
			if (this->rooms[i] == nullptr)
			{
				this->rooms[i] = &room;
			}
		}
		++numRooms;
	}
}

void Clinic::removeRoom(const Room & room)
{
	for (int i = 0; i < MAX_NUM_ROOMS; i++)
	{
		if (rooms[i] == &room)
		{
			rooms[i] = nullptr;
			--numRooms;
		}
	}
}

void Clinic::addTurn(Turn & turn)
{
	if (numTurns < MAX_NUM_TURNS)
	{
		for (int i = 0; i < MAX_NUM_TURNS; i++)
		{
			if (this->turns[i] == nullptr)
			{
				this->turns[i] = &turn;
			}
		}
		++numTurns;
	}
}

void Clinic::removeTurn(const Turn & turn)
{
	for (int i = 0; i < MAX_NUM_TURNS; i++)
	{
		if (turns[i] == &turn)
		{
			turns[i] = nullptr;
			--numTurns;
		}
	}
}

void Clinic::updateTurn(const Turn & oldturn, const Turn & newturn)
{
	//TODO
}

void Clinic::printStaff() const
{
	cout << "Printing staff.." << endl;
}

void Clinic::printPatients() const
{
	cout << "Printing patients.." << endl;
}

void Clinic::printRooms() const
{
	cout << "Printing rooms.." << endl;
}

void Clinic::printTurns() const
{
	cout << "Printing turns.." << endl;
}

void Clinic::setClinicManager(ClinicManager * new_manager)
{
	if (manager != new_manager)
	{
		if (manager != nullptr)
			manager->setClinic(nullptr);

		manager = new_manager;
		if (manager != nullptr)
			manager->setClinic(this);
	}
}