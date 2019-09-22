#ifndef __NURSE_H
#define __NURSE_H
#pragma warning(disable: 4996)
#include <iostream>
#include <string.h>
#include "MedicalStaff.h"
#define MAX_NURSE_SERVICES 20
using namespace std;

class Nurse : public MedicalStaff
{
private:
	char** services;
	int num_services;
public:
	Nurse(const MedicalStaff& medicalStaff, const char* the_service);	// Constructor
	Nurse(const Nurse& other); // copy constructor
	virtual ~Nurse();

	const Nurse& operator=(const Nurse& nurse);

	// Getters
	char** getServices() const { return services; }

	// Method
	void addServices(const char* service);

	int getNumServices() const { return num_services; };

	// Show
	void print() const;
};

#endif // !__NURSE_H
