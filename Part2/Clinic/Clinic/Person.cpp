#include "Person.h"
#pragma warning(disable: 4996)

Person::Person(int id, const char* name, const char* phone,
	int age, const Address& address, const eGender& gender) : address(address)
{
	this->id = id;
	this->name = strdup(name);
	this->phone = strdup(phone);
	this->age = age;
	this->gender = gender;
}

Person::Person(const Person & other) : address(other.address)
{
	this->id = other.id;
	this->name = strdup(other.name);
	this->phone = strdup(other.phone);
	this->age = other.age;
	this->gender = other.gender;
}

Person::Person(Person && other) : address(other.address)
{
	this->id = other.id;
	this->name = other.name;
	this->phone = other.phone;
	this->age = other.age;
	this->gender = other.gender;

	other.name = nullptr;
	other.phone = nullptr;
}

Person::~Person()
{
	delete[]name;
	delete[]phone;
}

void Person::setPhone(const char* phone)
{
	delete[]this->phone;
	phone = strdup(phone);
}
void Person::setAddress(Address& address)
{
	this->address = address;
}
void Person::toOs(ostream & os) const
{
	os << " " << getName() << " - id " << getId() << endl
		<< " Age " << getAge() << ", "
		<< displayGender() << endl
		<< " Phone - " << getPhone() << endl
		<< getAddress() << endl;
}
const char * Person::displayGender() const
{
	switch (gender) {
	case Person::Male:
		return "Male";
		break;
	case Person::Female:
		return "Female";
		break;
	default:
		return nullptr;
	}
}
ostream & operator<<(ostream & os, const Person & person)
{
	person.toOs(os);
	return os;
}