#pragma once
#ifndef _DRINK_H
#define _DRINK_H

#include "MenuItem.h"
#include <iostream>

using namespace std;

class Drink : public MenuItem {
protected:
	bool withIceCubes;

public:
	Drink(const MenuItem& item, bool iceCube = true);
	virtual ~Drink();

	bool getWithIceCubes() const;
	void setWithIceCubes(bool iceCube);
};
#endif
