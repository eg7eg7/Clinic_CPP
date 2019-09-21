#ifndef __DOCTOR_H
#define __DOCTOR_H

#include <iostream>
#include "MedicalStaff.h"
#include <string.h>

using namespace std;

class Doctor : public MedicalStaff
{

private:
	
	char* profession;
public:
	Doctor(const MedicalStaff& medicalStaff, const char* the_profession) 
		: MedicalStaff(medicalStaff) { profession = strdup(the_profession); };	// Constructor
	Doctor(const Doctor& other) : MedicalStaff(other), profession(NULL) { profession = strdup(other.getProfession()); }; // copy constructor
	virtual ~Doctor();

	const Doctor& operator=(const Doctor& doctor);

	// Getters
	const char* getProfession() const { return profession;}

	// Show
	void print() const; 

};



#endif // !__DOCTOR_H
