#include "Secretary.h"
#include "Clinic.h"
Secretary::Secretary(Secretary && Secretary) : Staff(std::move(Secretary)), OfficeStaff(std::move(Secretary))
{
	//nothing
}

void Secretary::callPatient(Patient & patient) const
{
	int length = Clinic::DEFAULT_TURN_LENGTH_MINS;
	cout << endl << this->getName() << ">> Hi, " << patient.getName() << ". My name is " << name << ", and " << endl;
	cout << this->getName() << ">> I'm calling to ask whether you want to make an appointment for your annual check-up" << endl;
	Patient::eStatus answer = patient.answerCall();
	if (answer != Patient::eStatus::HEALTHY)
	{

		MedicalStaff* medical = nullptr;
		if (answer == Patient::eStatus::REQUIRE_TREATMENT)
		{
			try {
				medical = &(clinic->getNurse());
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
			
		else if (answer == Patient::eStatus::SICK || medical == nullptr)
		{
			medical = patient.getPersonalDoctor();
		}
		
		Turn* turn = new Turn(*medical, patient, medical->getNextFreeTime(length), length);
		clinic->addTurn(*turn);
		cout << this->getName() << ">> Ok, I have created an appointment for you, please check the details :\n" << *turn << endl;
	}
	else
		cout << this->getName() << ">> Stay healthy!" << endl;
}

void Secretary::toOs(ostream & os) const
{
	os << "**Secretary**" << endl;
	OfficeStaff::toOs(os);
}

const Secretary & Secretary::operator=(const Secretary & other)
{
	if (this != &other)
	{
		OfficeStaff::operator=(other);
		//nothing
	}
	return *this;
}
