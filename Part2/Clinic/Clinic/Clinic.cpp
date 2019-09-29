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

void Clinic::printStaff(ostream & os) const
{
	os << endl <<"************ Printing staff at the clinic ****************" << endl;
	for(int i=0;i<numStaff;i++)
		os << *(staff[i]) << endl;
}

void Clinic::printPatients(ostream & os) const
{
	os << endl <<"************ Printing patients at the clinic ****************" << endl;
	for (int i = 0; i < numPatients; i++)
		os << *(patients[i]) << endl;
}

void Clinic::printRooms(ostream & os) const
{
	os << endl << "************ Printing rooms at the clinic ****************" << endl;

	for (int i = 0; i < numRooms; i++)
		os << *(rooms[i]) << endl;
}

void Clinic::printTurns(ostream & os) const
{
	os << endl << "************ Printing turns at the clinic ****************" << endl;

	for (int i = 0; i < numTurns; i++)
	{
		os << (*(turns[i])) << endl;
	}
		
}

void Clinic::setClinicManager(ClinicManager * new_manager)
{
	if (manager != new_manager)
	{
		if (manager != nullptr)
		{
			manager->setClinic(nullptr);
			removeStaff(*manager);
		}
		manager = new_manager;
		if (manager != nullptr)
		{
			manager->setClinic(this);
			addStaff(*new_manager);
		}
	}
}

ostream & operator<<(ostream & os, const Clinic & clinic)
{
	os << "**Clinic**" << endl;
	os << " Clinic name : " << clinic.getName() << endl;
	os << clinic.getAddress() << endl;
	os << " manager is " << clinic.getManager()->getName() << endl;

	clinic.printStaff(os);
	clinic.printPatients(os);
	clinic.printRooms(os);
	clinic.printTurns(os);

	return os;
}
