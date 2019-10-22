#pragma message("Adding Nurse")
#ifndef __NURSE_H
#define __NURSE_H
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include <vector>
#include "MedicalStaff.h"

using namespace std;

class Nurse : public MedicalStaff
{
public:
	static const int MAX_NURSE_SERVICES = 20;
protected:
	vector<string> services;
public:
	Nurse(const MedicalStaff& medicalStaff, const string& service);	// Constructor
	
	// Getters
	const vector<string>& getServices() const { return services; }

	// Method
	void addServices(const string& service);

	int getNumServices() const { return (int) services.size(); };

	// Show

	void Nurse::toOs(ostream & os) const override;
};

#endif // !__NURSE_H
