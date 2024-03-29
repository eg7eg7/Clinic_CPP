#ifndef __ADDRESS_H
#define __ADDRESS_H
#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>

using namespace std;
class Address
{
protected:

	char* country;
	char* city;
	char* street;
	int buildNum;
	int floorNum;
	int houseNum;

public:
	Address(const char* country, const char* city, const char* street, int buildNum, int floorNum, int houseNum);
	Address(const Address& other); // copy constructor
	Address(Address&& other); // move constructor

	~Address();

	const Address& operator=(const Address& address);

	// Getters
	const char* getCountry() const { return country; }
	const char* getCity() const { return city; }
	const char* getStreet() const { return street; }
	int getBuildNum() const { return floorNum; }
	int getFloorNum() const { return buildNum; }
	int getHouseNum() const { return houseNum; }

	// Setters
	void setCountry(const char* country);
	void setCity(const char* city);
	void setStreet(const char* street);
	void setBuildNum(const int& buildNum) { this->buildNum = buildNum; }
	void setFloorNum(const int& floor) { this->floorNum = floor; }
	void setHouseNum(const int& houseNum) { this->houseNum = houseNum; }

	// Show
	friend ostream& operator<<(ostream& os, const Address& add);
};

#endif // __ADDRESS_H
