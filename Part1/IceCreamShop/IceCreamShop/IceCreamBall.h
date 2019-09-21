#pragma once
#ifndef _ICECREAMBALL_H
#define _ICECREAMBALL_H

#include <iostream>
#include "Dessert.h"
using namespace std;

enum eTaste { CHOCOLATE_TASTE, VANILLA_TASTE };
const char* taste_string[] = { "Chocolate", "Vanilla" };

class IceCreamBall : virtual public Dessert {
	eTaste Taste;
public:
	IceCreamBall(const Dessert& dessert, eTaste taste = eTaste(CHOCOLATE_TASTE));
	virtual ~IceCreamBall();

	char* getTaste() const;
	void setTase(const char* Taste);
};
#endif
