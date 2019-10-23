#include "Address.h"

Address::Address(const string& country, const string& city, const string& street, int buildNum, int floorNum, int houseNum) :country(country), city(city), street(street)
{
	this->buildNum = buildNum;
	this->floorNum = floorNum;
	this->houseNum = houseNum;
}

ostream & operator<<(ostream & os, const Address & add)
{
	os << " Country: " << add.getCountry() << " \n City: " << add.getCity()
		<< " \n Street: " << add.getStreet() << " \n Building num: " << add.getBuildNum() << " Floor num: " <<
		add.getFloorNum() << " \n House num: " << add.getHouseNum() << endl;
	return os;
}