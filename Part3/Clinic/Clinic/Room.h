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
	int numOccupants;
private:
	Room(const Room& other); // private copy constructor

public:
	Room(Room&& other); // private move constructor
	Room(int roomNumber, int floor, int size) : roomNumber(roomNumber), floor(floor), size(size), numOccupants(0) {};	// Constructor

	// Getters
	const int& getRoomNumber() const { return roomNumber; }
	const int& getFloorNum() const { return floor; }
	const int& getSize() const { return size; }
	const bool isOccupied() const;

	// Setters
	const int& getNumOccupants() const { return numOccupants; };
	void addOccupant() { ++numOccupants; }
	void removeOccupant();
	// Show
	friend ostream & operator<<(ostream & os, const Room & room);
};

#endif // !__ROOM_H
