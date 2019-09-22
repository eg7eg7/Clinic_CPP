#ifndef __ROOM_H
#define __ROOM_H
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

class Room
{
private:

	int roomNumber;
	int floor;
	int size;
	bool occupied;

	Room(const Room& other); // private copy constructor

public:
	Room(int roomNumber, int floor, int size, bool occupied) : roomNumber(roomNumber), floor(floor), size(size), occupied(occupied) {};	// Constructor

	// Getters
	int getRoomNumber() const { return roomNumber; }
	int getFloor() const { return floor; }
	int getSize() const { return size; }
	bool isOccupied() const { return occupied; }

	// Setters
	void setOccupied(bool occupied) { this->occupied = occupied; }

	// Show
	void print() const;
};

#endif // !__ROOM_H
