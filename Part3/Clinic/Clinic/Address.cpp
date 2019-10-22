#include "Address.h"

Address::Address(const string& country, const string& city, const string& street, int buildNum, int floorNum, int houseNum) :country(country), city(city),street(street)
{
	this->buildNum = buildNum;
	this->floorNum = floorNum;
	this->houseNum = houseNum;
}

Address::Address(const Address & other) :country(other.country), city(other.city), street(other.street)
{
	this->buildNum = other.buildNum;
	this->floorNum = other.floorNum;
	this->houseNum = other.houseNum;
}

Address::Address(Address && other) : country(std::move(other.country)), city(std::move(other.city)), street(std::move(other.street))
{
	this->buildNum = other.buildNum;
	this->floorNum = other.floorNum;
	this->houseNum = other.houseNum;
}

Address::~Address()
{
	//nothing
}

const Address& Address::operator=(const Address & other)
{
	if (this != &other)
	{
		this->country = other.country;
		this->city = other.city;
		this->street = other.street;
		this->buildNum = other.buildNum;
		this->floorNum = other.floorNum;
		this->houseNum = other.houseNum;
	}
	return *this;
}



ostream & operator<<(ostream & os, const Address & add)
{
	os << " Country: " << add.getCountry() << " \n City: " << add.getCity()
		<< " \n Street: " << add.getStreet() << " \n Building num: " << add.getBuildNO() << " Floor num: " <<
		add.getFloor() << " \n House num: " << add.getHouseNO() << endl;
	return os;
}