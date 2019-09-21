#pragma once
#ifndef _EMPLOYEE_H
#include "IceCreamShop.h"
#include "Order.h"
#include "Date.h"
constexpr double MIN_SALARY = 29;
class IceCreamShop;

class Employee {
	static int next_id;
	const int ID;
	char* name;
	double salary;
	Date joiningDate;
	IceCreamShop *shop;
	Order* orders_done;

public:
	Employee(const char* name, double salary = MIN_SALARY) : joiningDate(Date()), ID(next_id++) {};
	Employee(const Employee& other);
	Employee(const Employee&& other);
	//make sure to fire employee from shop in d'tor
	virtual ~Employee();

	int getID() const;

	const char* getName() const;
	void setName(const char* new_name);

	double getSalary() const;
	void setSalary(double new_salary);

	IceCreamShop* getShop() const;
	void setShop(IceCreamShop* shop);

	Order* getOrdersDone() const;
	void setOrdersDone(Order* orders);

	/* returns the amount of days the employee has worked in the shop */
	int getSeniority() const;
	void prepareOrder(Order& order);

	bool operator==(const Employee& emp) const;
	bool operator!=(const Employee& emp) const;
	bool operator>(const Employee& emp) const;
	bool operator<(const Employee& emp) const;
	bool operator>=(const Employee& emp) const;
	bool operator<=(const Employee& emp) const;
};

int Employee::next_id = 1;
#endif //!_EMPLOYEE_H