#pragma once
#ifndef _SMOOTHIE_H
#define _SMOOTHIE_H

#include <iostream>

#include "Drink.h"
#include "Fruit.h"

using namespace std;

class Smoothie : public Drink {
	Fruit fruit;

public:

	Smoothie(const Drink drink, const Fruit& fruitt);
	Smoothie(Fruit&& fruitt);
	~Smoothie();
};
#endif
