#ifndef __ADDRESS_H
#define __ADDRESS_H
#pragma warning(disable: 4996)

#include <iostream>
#include <string>

using namespace std;
class Address
{
protected:

	string country;
	string city;
	string street;
	int buildNum;
	int floorNum;
	int houseNum;

public:
	Address(const string& country, const string& city, const string& street, int buildNum, int floorNum, int houseNum);

	// Getters
	const string& getCountry() const { return country; }
	const string& getCity() const { return city; }
	const string& getStreet() const { return street; }
	int getBuildNum() const { return floorNum; }
	int getFloorNum() const { return buildNum; }
	int getHouseNum() const { return houseNum; }

	// Setters
	void setCountry(const string& country) { this->country = country; };
	void setCity(const string& city) { this->city = city; };
	void setStreet(const string& street) { this->street = street; };
	void setBuildNum(const int& buildNum) { this->buildNum = buildNum; }
	void setFloorNum(const int& floor) { this->floorNum = floor; }
	void setHouseNum(const int& houseNum) { this->houseNum = houseNum; }

	// Show
	friend ostream& operator<<(ostream& os, const Address& add);
};

#endif // __ADDRESS_H
