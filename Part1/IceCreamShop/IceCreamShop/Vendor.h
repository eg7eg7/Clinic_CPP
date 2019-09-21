#pragma once
#ifndef _VENDOR_H
#include "Employee.h"
#include <iostream>
using namespace std;
class Vendor : public Employee
{
	Order* orders_taken;
public:
	Vendor();
	Vendor(const Vendor&& other);
	Vendor(const Vendor& other);
	Vendor(const Employee& other);
	~Vendor();

	void takeOrder(const Order& order) const;
};
#endif //!_VENDOR_H