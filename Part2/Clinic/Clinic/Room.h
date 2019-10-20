#pragma message("Adding Room")
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

public:
	Room(Room&& other); // private move constructor
	Room(int roomNumber, int floor, int size) : roomNumber(roomNumber), floor(floor), size(size), num_occupants(0) {};	// Constructor
	~Room() {};
	// Getters
	const int& getRoomNumber() const { return roomNumber; }
	const int& getFloor() const { return floor; }
	const int& getSize() const { return size; }
	const bool& isOccupied() const;

	// Setters
	const int& getNumOccupants() const { return num_occupants; };
	void addOccupant() { ++num_occupants; }
	void removeOccupant();
	// Show
	friend ostream & operator<<(ostream & os, const Room & room);
};

#endif // !__ROOM_H
