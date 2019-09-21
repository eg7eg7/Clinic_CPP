#pragma once
#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <iostream>
#include "Order.h"
using namespace std;

class Customer
{
	int customerID;
	char* name;
	double cashAmount;
	Order* orders;
public:
	Customer(const char* name, double cashAmount = 0);
	virtual ~Customer();

	Order& createOrder();

	const char* getName() const;
	void setName(char* Name);

	int getCustomerID() const;
	void setCustomerID(int CustomerID);

	double getcashAmount() const;
	void setcashAmount(double cashAmount);
};
#endif
