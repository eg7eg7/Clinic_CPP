#include "Person.h"
#pragma warning(disable: 4996)

Person::Person(int id, const char* name, const char* phone,
	int age, const Address& address, const eGender& gender) : address(address), name(NULL), phone(NULL)
{
	this->id = id;
	this->name = strdup(name);
	this->phone = strdup(phone);
	this->age = age;
	this->gender = gender;
}

Person::Person(const Person & other) : address(other.address)
{
	*this = other;
}

Person::Person(Person && other) : address(std::move(other.address)), name(NULL), phone(NULL)
{
	this->id = other.id;
	this->name = std::move(other.name);
	this->phone = std::move(other.phone);
	this->age = other.age;
	this->gender = other.gender;
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
void Person::setAddress(const Address& address)
{
	this->address = address;
}
const Person & Person::operator=(const Person & other)
{
	if (this != &other)
	{
		delete[]name;
		delete[]phone;

		this->id = other.id;
		this->name = strdup(other.name);
		this->phone = strdup(other.phone);
		this->age = other.age;
		this->gender = other.gender;
	}
	return *this;
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