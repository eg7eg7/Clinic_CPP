#pragma once
#ifndef _DESSERT_H
#define _DESSERT_H

#include <iostream>
#include "MenuItem.h"
using namespace std;

enum eDessertSize { SMALL_DESSERT, LARGE_DESSERT };

class Dessert : public MenuItem {
protected:
	eDessertSize size;

public:
	Dessert(const MenuItem& item, eDessertSize sizee = eDessertSize(SMALL_DESSERT));
	virtual ~Dessert();

	eDessertSize getSize() const;
	void setSize(const eDessertSize size);
};
#endif
