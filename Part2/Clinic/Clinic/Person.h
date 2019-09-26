#ifndef __PERSON_H
#define __PERSON_H
#pragma message("Adding Person")

#pragma warning(disable: 4996)
#include <iostream>
#include <string.h>
#include "Address.h"

using namespace std;


class Person
{
public:
	enum eGender { Male, Female };


private:

	int id;
	char* name;
	char* phone;
	int age;
	Address address;
	eGender gender;

public:
	Person(int id, const char* name, const char* phone, int age, const Address& address, const eGender& gender);	// Constructor
	Person(const Person& other); // copy constructor
	virtual ~Person();

	// Getters
	int getId() const { return id; }
	const char* getName() const { return name; }
	const char* getPhone() const { return phone; }
	const int getAge() const { return age; }
	const eGender getGender() const { return gender; };
	const Address& getAddress() const { return address; };

	// Setters
	void setPhone(const char* phone);
	void setAddress(Address& address);

	// Show
	friend ostream & operator<<(ostream & os, const Person & person);
	virtual void toOs(ostream& os) const;
	const char* displayGender() const;
};

#endif // !__PERSON_H
