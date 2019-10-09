#ifndef __ROOM_H
#define __ROOM_H

#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

class Room
{
protected:

	int roomNumber;
	int floor;
	int size;
	int num_occupants;
private:
	Room(const Room& other); // private copy constructor
	Room(const Room&& other); // private move constructor

public:
	Room(int roomNumber, int floor, int size) : roomNumber(roomNumber), floor(floor), size(size), num_occupants(0) {};	// Constructor
	virtual ~Room() {};
	// Getters
	int getRoomNumber() const { return roomNumber; }
	int getFloor() const { return floor; }
	int getSize() const { return size; }
	bool isOccupied() const { 
	if(num_occupants > 0)
		return true;
	else 
		return false;
	}

	// Setters
	int getNumOccupants() const { return num_occupants; };
	void addOccupant() { ++num_occupants; }
	void removeOccupant() {
		if (num_occupants > 0)
			--num_occupants;
	}
	// Show
	friend ostream & operator<<(ostream & os, const Room & room);

};

#endif // !__ROOM_H
