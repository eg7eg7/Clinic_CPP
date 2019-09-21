#pragma once
#ifndef _MENU_H

#include <iostream>
#include "MenuItem.h"
using namespace std;

class Menu {
	MenuItem* items;

public:
	Menu();
	Menu(const Menu& menu);
	virtual ~Menu();
	void printMenu() const;
	void addMenuItem(const MenuItem& item);
	void removeMenuItem(int itemID);
	friend ostream& operator<<(ostream& os, const Menu& menu);
};
#endif // !_MENU_H
