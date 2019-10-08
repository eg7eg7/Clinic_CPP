#ifndef __DOCTOR_H
#define __DOCTOR_H
#pragma warning(disable: 4996)

#include <iostream>
#include "Staff.h"
#include "MedicalStaff.h"
#include <string.h>
using namespace std;

class Doctor : public MedicalStaff
{
private:

	char* profession;
	Doctor(const Doctor&& other);
	Doctor(const MedicalStaff&& medicalStaff, const char* profession);

public:
	Doctor(const MedicalStaff& medicalStaff, const char* profession)
		: Staff(medicalStaff), MedicalStaff(medicalStaff) {
		this->profession = strdup(profession);
	};	// Constructor
	Doctor(const Doctor& other) : Staff(other), MedicalStaff(other), profession(nullptr) { this->profession = strdup(other.profession); }; // copy constructor
	virtual ~Doctor();

	const Doctor& operator=(const Doctor& doctor);

	// Getters
	const char* getProfession() const { return profession; }

	// Show
	
	void toOs(ostream & os) const override;

};

#endif // !__DOCTOR_H
