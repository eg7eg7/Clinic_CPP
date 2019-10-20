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
	*this = other;
}

Clinic::Clinic(Clinic && other) : address(std::move(other.address))
{
	this->name = std::move(other.name);

	numRooms = other.numRooms;
	numStaff = other.numStaff;
	numPatients = other.numPatients;
	numTurns = other.numTurns;
	manager = std::move(manager);
	manager->setClinic(this);

	rooms = std::move(other.rooms);
	staff = std::move(other.staff);
	patients = std::move(other.patients);
	turns = std::move(other.turns);
}

Clinic::~Clinic()
{
	setClinicManager(nullptr);
	for (int i = 0; i < MAX_NUM_TURNS; i++)
	{
		delete turns[i];
	}
	delete[]name;
	delete[]rooms;
	delete[]staff;
	delete[]patients;
	delete[]turns;
}

void Clinic::addStaff(Staff * staff)
{
	if (&staff != nullptr && staff->getClinic() == nullptr)
	{
		bool exists = false;
		int index = -1;

		for (int i = 0; i < MAX_NUM_STAFF; i++)
		{
			if (staff == this->staff[i])
			{
				exists = true;
			}
			if (exists)
			{
				index = i;
				break;
			}
			if (this->staff[i] == nullptr)
				index = i;
		}

		if (!exists && numStaff < MAX_NUM_STAFF)
		{
			this->staff[index] = staff;
			++numStaff;
		}
		staff->setClinic(this);
	}
}

const Clinic& Clinic::operator=(const Clinic & other)
{
	if (this != &other)
	{
		delete[]this->name;
		delete[]this->rooms;
		delete[]this->staff;
		delete[]this->patients;
		delete[]this->turns;

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
	return *this;
}

void Clinic::removeStaff(Staff & staff)
{
	for (int i = 0; i < MAX_NUM_STAFF; i++)
	{
		if (this->staff[i] == &staff)
		{
			staff.setClinic(nullptr);
			this->staff[i] = nullptr;

			--numStaff;
			break;
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
				++numPatients;
				break;
			}
		}
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
			break;
		}
	}
}

void Clinic::checkPatients()
{
	cout << "******************************************************" << endl;
	cout << "Checking patients status and creating new appointments" << endl;
	cout << "******************************************************" << endl;
	try {
		for (int i = 0; i < MAX_NUM_PATIENTS; i++)
		{
			if (patients[i] != nullptr)
			{
				const Secretary& s = getSecretary();
				s.callPatient(*(patients[i]));
				cout << "-----------------------------------------" << endl;
			}
		}
	}
	catch (const char*& msg)
	{
		cout << msg << endl;
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
				++numRooms;
				this->rooms[i] = &room;
				break;
			}
		}
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
			break;
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
				turn.getMedicalStaff()->addTurn(turn);
				++numTurns;
				break;
			}
		}
	}
	Turn::sortTurns(turns, MAX_NUM_TURNS);
}

void Clinic::removeTurn(const Turn & turn)
{
	for (int i = 0; i < MAX_NUM_TURNS; i++)
	{
		if (turns[i] == &turn)
		{
			turns[i] = nullptr;
			--numTurns;
			break;
		}
	}
	Turn::sortTurns(turns, MAX_NUM_TURNS);
}

void Clinic::printStaff(ostream & os) const
{
	int printed = 0;
	os << endl << "************ Printing staff at the clinic ****************" << endl;
	for (int i = 0; i < MAX_NUM_STAFF; i++)
		if (&(*(staff[i])) != nullptr && printed < numStaff)
		{
			os << *(staff[i]) << endl;
			os << "****************************************" << endl;
			++printed;
		}
}

void Clinic::printPatients(ostream & os) const
{
	int printed = 0;
	os << endl << "************ Printing patients at the clinic ****************" << endl;
	for (int i = 0; i < MAX_NUM_PATIENTS; i++)
		if (&(*(patients[i])) != nullptr && printed < numPatients)
		{
			os << *(patients[i]) << endl;
			++printed;
		}
}

void Clinic::printRooms(ostream & os) const
{
	os << endl << "************ Printing rooms at the clinic ****************" << endl;
	int printed = 0;
	for (int i = 0; i < MAX_NUM_ROOMS; i++)
		if (&(*(rooms[i])) != nullptr && printed < numRooms)
		{
			os << *(rooms[i]) << endl;
			++printed;
		}
}

void Clinic::printTurns(ostream & os) const
{
	os << endl << "************ Printing turns at the clinic ****************" << endl;
	int printed = 0;
	for (int i = 0; i < MAX_NUM_TURNS; i++)
	{
		if (&(*(turns[i])) != nullptr && printed < numTurns)
		{
			os << *(turns[i]) << endl;
			++printed;
		}
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
			addStaff(new_manager);
		}
	}
}

void Clinic::setAddress(const Address & address)
{
	this->address = address;
}

void Clinic::setName(const char * new_name)
{
	if (strcmp(this->name, new_name))
	{
		delete[]this->name;
		this->name = strdup(new_name);
	}
}

const Secretary& Clinic::getSecretary() const throw (const char*)
{
	static int last_index = 0;
	Secretary* p;
	if (last_index == MAX_NUM_STAFF)
		last_index = 0;
	int i = last_index, count = 0;

	while (count < MAX_NUM_STAFF)
	{
		if (nullptr != (p = dynamic_cast<Secretary*>(staff[i])))
		{
			last_index = i + 1;

			return *p;
		}
		++i;
		if (i == MAX_NUM_STAFF)
			i = 0;
		++count;
	}
	throw "No secretaries at the clinic!";
}

Nurse& Clinic::getNurse() const throw (const char*)
{
	static int last_index = 0;
	Nurse* p;
	if (last_index == MAX_NUM_STAFF)
		last_index = 0;
	int i = last_index, count = 0;

	while (count < MAX_NUM_STAFF)
	{
		if (nullptr != (p = dynamic_cast<Nurse*>(staff[i])))
		{
			last_index = i + 1;

			return *p;
		}
		++i;
		if (i == MAX_NUM_STAFF)
			i = 0;
		++count;
	}
	throw "No nurses at the clinic!";
}

ostream & operator<<(ostream & os, const Clinic & clinic)
{
	os << "**Clinic**" << endl;
	os << " Clinic name : " << clinic.getName() << endl;
	os << clinic.getAddress() << endl;
	if (clinic.getManager() != nullptr)
		os << " manager is " << clinic.getManager()->getName() << endl;

	clinic.printTurns(os);
	clinic.printRooms(os);
	clinic.printPatients(os);
	clinic.printStaff(os);

	return os;
}