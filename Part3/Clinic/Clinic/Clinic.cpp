#include "Clinic.h"

Clinic::Clinic(const string& name, const Address & address) : address(address), name(name)
{
	manager = nullptr;
	reserveVectors();
}


Clinic::Clinic(Clinic && other) : address(std::move(other.address)), name(std::move(other.name))
{
	reserveVectors();
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
	for (auto it = staff.begin(); it != staff.end(); ++it)
		delete *it;
	for (auto it = rooms.begin(); it != rooms.end(); ++it)
		delete *it;
	for (auto it = patients.begin(); it != patients.end(); ++it)
		delete *it;
	for (auto it = turns.begin(); it != turns.end(); ++it)
		delete *it;
}

void Clinic::addStaff(Staff * newStaff)
{
	if (newStaff != nullptr && newStaff->getClinic() == nullptr && staff.size() < MAX_NUM_STAFF)
	{
		//check if staff exists
		vector<Staff*>::iterator iterFound = find(staff.begin(), staff.end(), newStaff);
		//if not, add
		if (iterFound == staff.end())
		{
			staff.push_back(newStaff);
		}
		newStaff->setClinic(this);
	}
}


void Clinic::removeStaff(Staff & newStaff)
{
	for (auto it = staff.begin(); it != staff.end(); ++it)
		if ((*it) == &newStaff)
		{
			newStaff.setClinic(nullptr);
			delete *it;
			staff.erase(it);
			break;
		}
}

void Clinic::reserveVectors()
{
	staff.reserve(MAX_NUM_STAFF);
	patients.reserve(MAX_NUM_PATIENTS);
	rooms.reserve(MAX_NUM_ROOMS);
	turns.reserve(MAX_NUM_TURNS);
}

void Clinic::addPatient(Patient * patient)
{
	if (patients.size() < MAX_NUM_PATIENTS && patient != nullptr)
	{
		vector<Patient*>::iterator iterFound = find(patients.begin(), patients.end(), patient);
		if (iterFound == patients.end())
		{
			patients.push_back(patient);
		}
	}
}

void Clinic::removePatient(const Patient & patient)
{
	for (auto it = patients.begin(); it != patients.end(); ++it)
		if ((*it) == &patient)
		{
			delete *it;
			patients.erase(it);
			break;
		}
}

void Clinic::checkPatients()
{
	cout << endl << "******************************************************" << endl;
	cout << "Checking patients status and creating new appointments" << endl;
	cout << "******************************************************" << endl;
	try {
		for (auto it = patients.begin(); it != patients.end(); ++it)
		{
				Secretary& s = getSecretary();
				s.callPatient(**it);
				cout << "-----------------------------------------" << endl;
		}
	}
	catch (const string msg)
	{
		cout << msg << endl;
	}
}

void Clinic::addRoom(Room * room)
{
	if (room != nullptr && rooms.size() < MAX_NUM_ROOMS)
	{
		vector<Room*>::iterator iterFound = find(rooms.begin(), rooms.end(), room);

		if (iterFound == rooms.end())
		{
			rooms.push_back(room);
		}
	}
}

void Clinic::removeRoom(const Room & room)
{
	for (auto it = rooms.begin(); it != rooms.end(); ++it)
		if ((*it) == &room)
		{
			delete *it;
			rooms.erase(it);
			break;
		}
}

void Clinic::addTurn(Turn & turn)
{
	if (turns.size() < MAX_NUM_ROOMS)
	{
		vector<Turn*>::iterator iterFound = find(turns.begin(), turns.end(), &turn);

		if (iterFound == turns.end())
		{
			turns.push_back(&turn);
		}
	}
	std::sort(turns.begin(),turns.end(),Turn::compareTurnPointer);
}

void Clinic::removeTurn(const Turn & turn)
{
	for (auto it = turns.begin(); it != turns.end(); ++it)
		if ((*it) == &turn)
		{
			delete *it;
			turns.erase(it);
			break;
		}
	std::sort(turns.begin(), turns.end(), Turn::compareTurnPointer);
}

void Clinic::printStaff(ostream & os) const
{
	os << endl << "************ Printing staff at the clinic ****************" << endl;
	for (auto it = staff.begin(); it != staff.end(); ++it)
	{
		os << **it << endl;
		os << "****************************************" << endl;
	}
}

void Clinic::printPatients(ostream & os) const
{
	os << endl << "************ Printing patients at the clinic ****************" << endl;
		for (auto it = patients.begin(); it != patients.end(); ++it)
		{
			os << **it << endl;
		}
}

void Clinic::printRooms(ostream & os) const
{
	os << endl << "************ Printing rooms at the clinic ****************" << endl;
	for (auto it = rooms.begin(); it != rooms.end(); ++it)
	{
		os << **it << endl;
	}
}

void Clinic::printTurns(ostream & os) const
{
	os << endl << "************ Printing turns at the clinic ****************" << endl;
	for (auto it = turns.begin(); it != turns.end(); ++it)
	{
		os << **it << endl;
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



Secretary& Clinic::getSecretary() const throw (const string)
{
	static Staff* last_secretary = nullptr;
	vector<Staff*>::const_iterator iter = iter = staff.begin();
	if (!last_secretary)
	{
		vector<Staff*>::const_iterator iter = find(staff.begin(), staff.end(), last_secretary);
		if (iter == staff.end())
			iter = staff.begin();
	}

	Secretary* p;
	int count = 0;
	while (count < staff.size() && iter != staff.end())
	{
		if (nullptr != (p = dynamic_cast<Secretary*>(*iter)))
		{
			last_secretary = *iter;
			return *p;
		}
		++iter;
		if (iter == staff.end())
			iter = staff.begin();
		++count;
	}
	throw string("No secretaries at the clinic!");
}

Nurse& Clinic::getNurse() const throw (const string)
{
	static Staff* last_nurse = nullptr;
	vector<Staff*>::const_iterator iter;
	if (!last_nurse)
	{
		vector<Staff*>::const_iterator iter = find(staff.begin(), staff.end(), last_nurse);
		if (iter == staff.end())
			iter = staff.begin();
	}
	else
		iter = staff.begin();

	Nurse* p;
	int count = 0;
	while (count < staff.size() && iter != staff.end())
	{
		if (nullptr != (p = dynamic_cast<Nurse*>(*iter)))
		{
			last_nurse = *iter;
			return *p;
		}
		++iter;
		if (iter == staff.end())
			iter = staff.begin();
		++count;
	}
	throw string("No nurses at the clinic!");
}

ostream & operator<<(ostream & os, const Clinic & clinic)
{
	os << "********************************Clinic********************************" << endl;
	os << " Clinic name : " << clinic.getName() << endl;
	os << clinic.getAddress() << endl;
	if (clinic.getManager() != nullptr)
		os << " manager is " << clinic.getManager()->getName() << endl;

	
	//os << turns << endl; //TODO
	clinic.printTurns(os);
	clinic.printRooms(os);
	clinic.printPatients(os);
	clinic.printStaff(os);

	return os;
}