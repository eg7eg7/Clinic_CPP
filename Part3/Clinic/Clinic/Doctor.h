#pragma message("Adding Doctor")
#ifndef __DOCTOR_H
#define __DOCTOR_H
#pragma warning(disable: 4996)

#include <iostream>
#include "MedicalStaff.h"
#include <string.h>
using namespace std;

class Doctor : public MedicalStaff
{
protected:

	string profession;
public:
	Doctor(const Doctor&& other);
	Doctor(const MedicalStaff&& medicalStaff, const string& profession);
	Doctor(const MedicalStaff& medicalStaff, const string& profession);	// Constructor
	Doctor(const Doctor& other); // copy constructor
	virtual ~Doctor();

	const Doctor& operator=(const Doctor& doctor);

	// Getters
	const string& getProfession() const { return profession; }

	// Show

	void toOs(ostream & os) const override;
};

#endif // !__DOCTOR_H
