#ifndef __ROOM_H
#define __ROOM_H


class Room
{

private:

	int roomNumber;
	int floor;
	int size;
	bool occupied;

	Room(const Room& other); // private copy constructor


public:
	Room(int roomNumber,int floor ,int size ,bool occupied);	// Constructor

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
