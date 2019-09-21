#ifndef __PERSON_H
#define __PERSO_H


#include "Address.h"

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
	Person(int id ,const char* name ,const char* phone ,int age ,const Address& address ,const eGender& gender);	// Constructor
	Person(const Person& other); // copy constructor
	~Person();

	void operator=(const Person& person);

	// Getters
	int getId() const { return id; }
	const char* getName() const { return name; }
	const char* getPhone() const { return phone; }
	int getAge() const { return age; }
	eGender getGender() const;
	Address getAddress() const;


	// Setters
	void setPhone(const char* phone);
	void setAddress(Address& address);

	// Show
	void print() const;

};


#endif // !__PERSON_H
