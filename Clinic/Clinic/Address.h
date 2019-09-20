#ifndef __ADDRESS_H
#define __ADDRESS_H

class Address
{

private:

	char* country;
	char* city;
	char* street;
	int buildNO;
	int floorNO;
	int houseNO;




public:
	Address(const char* country ,const char* city ,const char* street ,int buildNO ,int floorNO ,int houseNO);
	Address(const Address& other); // copy constructor
	~Address();

	void operator=(const Address& address);


	// Getters
	const char* getCountry() const { return country; }
	const char* getCity() const { return city; }
	const char* getStreet() const { return street; }
	int getBuildNO() const { return floorNO; }
	int getFloor() const { return buildNO; }
	int getHouseNO() const { return houseNO; }


	// Setters
	void setCountry(const char* country);
	void setCity(const char* city);
	void setStreet(const char* street);
	void setBuildNO(int floor) { this->buildNO = floor; }
	void setFloorNO(int floor) { this->floorNO = floor; }
	void setHouseNO(int houseNO) { this->houseNO = houseNO; }

	// Show
	void print() const;


};


#endif // __ADDRESS_H
