#pragma once
#ifndef _SYRUP_H
#define _SYRUP_H

#include <iostream>
#include "Dessert.h"
using namespace std;

enum eSyrup { MAPLE_SYRUP, CHOCOLATE_SYRUP, RASPBERRY_SYRUP };
char* syrup_string[] = { "Maple", "Chocolate","Raspberry" };

class BelgianWaffle : virtual public Dessert {
	eSyrup Syrup;
public:
	BelgianWaffle(const Dessert& dessert, eSyrup syrup = MAPLE_SYRUP);
	virtual ~BelgianWaffle();

	const char* getSyrup() const;
	void setSyrup(const char* Syrup);
};
#endif
