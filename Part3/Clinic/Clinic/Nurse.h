#pragma message("Adding Nurse")
#ifndef __NURSE_H
#define __NURSE_H
#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "MedicalStaff.h"

using namespace std;

class Nurse : public MedicalStaff
{
public:
	static const int MAX_NURSE_SERVICES = 20;
protected:
	string* services;
	int numServices;
public:
	Nurse(const MedicalStaff& medicalStaff, const string& service);	// Constructor
	Nurse(const Nurse& other); // copy constructor
	Nurse(Nurse&& other); // move constructor
	virtual ~Nurse();

	const Nurse& operator=(const Nurse& nurse);

	// Getters
	string* getServices() const { return services; }

	// Method
	void addServices(const string& service);

	int getNumServices() const { return numServices; };

	// Show

	void Nurse::toOs(ostream & os) const override;
};

#endif // !__NURSE_H
