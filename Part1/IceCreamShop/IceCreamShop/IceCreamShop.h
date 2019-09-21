#pragma once
#ifndef _IceCreamShop_H

#include <iostream>
#include "Menu.h"
#include "Vendor.h"
#include "Date.h"
using namespace std;

class IceCreamShop
{
	char* name;
	char* address;
	const Date creationDate;
	Menu menu;
protected:
	Employee* employees;
	double cashAmount;
public:
	IceCreamShop(const char* name, const char* address, Menu& menu);
	IceCreamShop(const char* name, const char* address);
	IceCreamShop(const IceCreamShop& other);
	~IceCreamShop();

	Menu& getMenu() { return menu; };

	const char* getName() const;
	void setName(const char* new_name);

	const char* getAddress() const;
	void setAddress(const char* new_address);

	const Date getDate() const;

	double getCashAmount() const;
	Employee* getEmployees() const;

	/* return 1 if added successfully, -1 otherwise */
	int addEmployee(const Employee& newEmployee);

	/* return 1 if added successfully, -1 otherwise */
	int removeEmployee(int employeeId);

	/* returns an available vendor in the shop for customer service and taking orders*/
	Vendor* getAvailableVendor() const;

	/* returns an available employee in the shop*/
	Employee* getAvailableEmployee() const;
};
#endif // !_IceCreamShop_H
