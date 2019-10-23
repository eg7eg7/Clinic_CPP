#ifndef __PERSON_H
#define __PERSON_H

#pragma warning(disable: 4996)
#include <iostream>
#include <string.h>

#include "Address.h"

using namespace std;

class Person
{
public:
	enum eGender { Male, Female };

protected:

	int id;
	string name;
	string phone;
	int age;
	Address address;
	eGender gender;

public:
	Person(int id, const string& name, const string& phone, int age, const Address& address, const eGender& gender);	// Constructor

	virtual ~Person() {};

	// Getters
	const int& getId() const { return id; }
	const string& getName() const { return name; }
	const string& getPhone() const { return phone; }
	const int& getAge() const { return age; }
	const eGender& getGender() const { return gender; };
	const Address& getAddress() const { return address; };

	// Setters
	void setPhone(const string& phone);
	void setAddress(const Address& address);

	// Show
	friend ostream & operator<<(ostream & os, const Person & person);
	virtual void toOs(ostream& os) const;
	const string displayGender() const;
};

#endif // !__PERSON_H
