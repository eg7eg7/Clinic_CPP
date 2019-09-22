#include "Address.h"

Address::Address(const char * country, const char * city, const char * street, int buildNum, int floorNum, int houseNum)
{
	this->country = strdup(country);
	this->city = strdup(city);
	this->street = strdup(street);
	this->buildNum = buildNum;
	this->floorNum = floorNum;
	this->houseNum = houseNum;
}

Address::Address(const Address & other)
{
	this->country = strdup(other.country);
	this->city = strdup(other.city);
	this->street = strdup(other.street);
	this->buildNum = other.buildNum;
	this->floorNum = other.floorNum;
	this->houseNum = other.houseNum;
}

Address::~Address()
{
	delete[]country;
	delete[]city;
	delete[]street;
}

void Address::operator=(const Address & other)
{
	if (this != &other)
	{
		delete[]country;
		delete[]city;
		delete[]street;

		this->country = strdup(other.country);
		this->city = strdup(other.city);
		this->street = strdup(other.street);
		this->buildNum = other.buildNum;
		this->floorNum = other.floorNum;
		this->houseNum = other.houseNum;
	}
}

void Address::setCountry(const char * country)
{
	delete[]this->country;
	this->country = strdup(country);
}

void Address::setCity(const char * city)
{

	delete[]this->city;
	this->city = strdup(city);
}

void Address::setStreet(const char * street)
{

	delete[]this->street;
	this->street = strdup(street);
}

void Address::print() const
{
	cout << "in Address" << endl;
}
