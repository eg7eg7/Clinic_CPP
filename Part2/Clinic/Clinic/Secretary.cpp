#include "Secretary.h"

void Secretary::callPatient(Patient & patient)
{
	cout << "Hi, " << patient.getName() << ". My name is " << name << ", and " << endl;
	cout << "I'm calling to ask whether you want to make an appointment for your annual check-up" << endl;
	cout << "Press 1 if yes, 0 if not." << endl;
	int answer = patient.answerCall();
	if (answer)
	{
		Doctor* doctor = patient.getPersonalDoctor();
		Turn turn(*doctor, patient, doctor->getNextFreeTime(30), 30);

		//TODO add clinic (in Staff)
		//clinic.addTurn(turn);
	}
}

void Secretary::toOs(ostream & os) const
{
	os << "**Secretary**" << endl;
	OfficeStaff::toOs(os);
}