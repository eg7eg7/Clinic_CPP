#ifndef __STAFF_H
#define __STAFF_H

#include "Person.h"

class Staff : public Person
{

private:
	long extention;
	long salary;



public:
	Staff(const Person& person ,long extention ,long salary);	//Constructor
	Staff(const Staff& staff);

	// Getters
	long getExtention() const { return extention; }
	long getSalary() const { return salary; }


	// Setters
	void setSalary(long salary) { this->salary = salary; }



	// Show
	void print() const;	


};



#endif // !__STAFF_H
