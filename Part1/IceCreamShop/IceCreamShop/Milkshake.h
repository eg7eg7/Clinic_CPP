#pragma once
#ifndef _MILKESHAKE_H
#define _MILKESHAKE_H

#include <iostream>
#include "iceCreamBall.h"
#include "Drink.h"

using namespace std;

enum eDrinkTaste { VANILLA_DTASTE, CHOCOLATE_DTASTE, COFFEE_DTASTE, BERRY_DTASTE };

class Milkshake : public Drink {
protected:
	IceCreamBall iceCreamBall;
	eDrinkTaste taste;

public:
	Milkshake(const Drink drink, eDrinkTaste drinkTaste = eDrinkTaste(BERRY_DTASTE));
	~Milkshake();

	eDrinkTaste getTaste() const;
	void setTaste(eDrinkTaste Taste);

	const IceCreamBall& getIceCream() const;
};
#endif
