#ifndef __PATIENT_H
#define __PATIENT_H


#include "Person.h"
#include "Turn.h"
#include "Doctor.h"

const int MAX_TURNS_SIZE = 20;

class Patient : public Person
{

private:
	
	Turn** turns;
	bool clinicMember;
	Doctor personalDoctor;
	


public:
	Patient(const Person& person ,const Doctor& personalDoctor ,bool clinicMember); // Constructor
	Patient(const Patient& other); // copy constructor
	~Patient();

	void operator=(const Patient& patient);

	// Methods
	void answerCall();
	void changeDoctor(const Doctor& doctor);
	void changeClinicMember(bool clinicMember);

	// Show
	void print() const;

};


#endif // !__PATIENT_H
