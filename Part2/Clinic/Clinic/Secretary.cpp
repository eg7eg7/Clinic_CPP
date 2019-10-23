#include "Secretary.h"
#include "Clinic.h"

void Secretary::callPatient(Patient & patient) const
{
	int length = Clinic::DEFAULT_TURN_LENGTH_MINS;
	cout << "Making a call to patient " << patient.getName() << "...." << endl;
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

		if (answer == Patient::eStatus::SICK || medical == nullptr)
		{
			medical = patient.getPersonalDoctor();
		}
		try {
			Time t = medical->getNextFreeTime(length);
			Turn* turn = new Turn(*medical, patient, t, length);
			clinic->addTurn(*turn);
			cout << this->getName() << ">> Ok, I have created an appointment for you, please check the details :\n\n" << *turn << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << this->getName() << ">> I'm sorry there are isn't a time slot available for you. try again tomorrow." << endl;
		}
	}
	else
		cout << this->getName() << ">> Stay healthy!" << endl;
}

void Secretary::toOs(ostream & os) const
{
	os << "**Secretary**" << endl;
	OfficeStaff::toOs(os);
}