#pragma once
#ifndef _FRUIT_H
#define _FRUIT_H

#include <iostream>
using namespace std;

enum eFruit { MANGO, BANANA, STRAWBERRY };
char* fruits[] = { "Mango", "Banana", "Strawberry" };

class Fruit {
	eFruit type;

public:
	Fruit(eFruit f = MANGO);
	virtual ~Fruit();

	eFruit getType() const;
	void setType(const eFruit fruit_type);
};
#endif
