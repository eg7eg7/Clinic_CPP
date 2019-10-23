#include "Turn.h"

Turn::Turn(MedicalStaff& medicalStaff, Patient& patient, Time startTime, long sessionDurationMins)
{
	this->medicalStaff = &medicalStaff;
	this->patient = &patient;

	this->startTime = startTime;
	this->sessionDurationMins = sessionDurationMins;
}

Turn::Turn(const Turn & other)
{
	*this = other;
}

Time Turn::getEndTime() const
{
	int newMin = (startTime.getMinute() + sessionDurationMins) % 60;
	int newHour = (startTime.getHour() + ((startTime.getMinute() + sessionDurationMins) / 60)) % 24;

	return Time(newHour, newMin);
}

void Turn::setStartTime(const Time & time)
{
	startTime = time;
}

void Turn::setDurationsMins(const int & time)
{
	sessionDurationMins = time;
}

void Turn::changeStartTime(const Time& startTime)
{
	this->startTime = startTime;
}

void Turn::changeDuration(const long& sessionDurationMins)
{
	this->sessionDurationMins = sessionDurationMins;
}

void Turn::changeMedicalStaff(MedicalStaff* medicalStaff)
{
	if (medicalStaff != this->medicalStaff)
	{
		if (this->medicalStaff != nullptr)
			this->medicalStaff->deleteTurn(*this);
		this->medicalStaff = medicalStaff;
	}
}

void Turn::sortTurns(Turn** turns, const int& size)
{
	int count = -1;
	//defrag - nullptrs at the end of array
	for (int i = 0; i < size; i++)
	{
		if (turns[i] == nullptr)
			count = i;
		if (count != -1 && turns[i] != nullptr)
		{
			turns[count] = turns[i];
			turns[i] = nullptr;
			count = -1;
		}
	}
	//Bubble sort
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (turns[i] != nullptr && turns[i + 1] != nullptr)
			{
				//check
				if (((*(turns[i])).getStartTime() > (*(turns[i + 1])).getStartTime()))
				{
					//swap
					std::swap(turns[i], turns[i + 1]);
				}
			}
		}
	}
}

void Turn::changePatient(Patient* patient)
{
	if (patient != this->patient)
	{
		if (this->patient != nullptr)
			this->patient->deleteTurn(*this);
		this->patient = patient;
	}
}

const Turn & Turn::operator=(const Turn & other)
{
	if (this != &other)
	{
		this->medicalStaff = other.medicalStaff;
		this->patient = other.patient;
		this->startTime = other.startTime;
		this->sessionDurationMins = other.sessionDurationMins;
	}
	return *this;
}

bool Turn::operator==(const Turn & other) const
{
	if (this == &other)
		return true;
	if (other.medicalStaff == medicalStaff &&
		other.patient == patient &&
		other.startTime == startTime &&
		other.sessionDurationMins == sessionDurationMins)
		return true;

	return false;
}
bool Turn::operator>(const Turn & other) const
{
	return startTime > other.startTime;
}
bool Turn::operator<(const Turn & other) const
{
	return !operator>(other);
}
ostream & operator<<(ostream & os, const Turn & turn)
{
	os << "Turn [Starts : " << turn.getStartTime() << ", duration: " << turn.getDurationMins() << "mins , patient " << (turn.getPatient())->getName()
		<< " , Staff: " << (turn.getMedicalStaff())->getName() << " ]"<<endl;
	return os;
}