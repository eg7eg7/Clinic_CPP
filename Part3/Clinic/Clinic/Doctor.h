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
	Doctor(const MedicalStaff&& medicalStaff, const string& profession);
	Doctor(const MedicalStaff& medicalStaff, const string& profession);	// Constructor


	// Getters
	const string& getProfession() const { return profession; }

	// Show

	void toOs(ostream & os) const override;
};

#endif // !__DOCTOR_H
