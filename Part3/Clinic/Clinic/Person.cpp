#include "Person.h"
#pragma warning(disable: 4996)

Person::Person(int id, const string& name, const string& phone,
	int age, const Address& address, const eGender& gender) : address(address), name(name), phone(phone)
{
	this->id = id;
	this->age = age;
	this->gender = gender;
}

void Person::setPhone(const string& phone)
{
	this->phone = phone;
}
void Person::setAddress(const Address& address)
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

const string Person::displayGender() const
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