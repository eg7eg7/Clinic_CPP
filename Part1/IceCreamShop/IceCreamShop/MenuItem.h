#ifndef _MENUITEM_H
#define _MENUITEM_H

#include <iostream>
#include "Menu.h"

using namespace std;

enum eItemId { CREPE, ICE_CREAM, BELGIAN_WAFFLE, ICE_CREAM_WITH_BELGIAN_WAFFLE, CREPE_ICE_CREAM, SMOOTHIE, MILKSHAKE };
char* itemString[] = { "Crepe", "Belgian Waffle", "Ice Cream with Belgian Waffle", "Crepe with Ice Cream", "Smoothie", "Milkshake" };

class MenuItem
{
protected:
	const eItemId ItemID;

	char* description;
	double price;
	char* ingredents;

public:
	MenuItem(const eItemId id, const char* descriptions, double price, const char* ingredients);
	virtual ~MenuItem();

	/* checks ingredients and returns a boolean*/
	bool isContainingMilk();
	bool isContainingNuts();

	virtual int getItemID() const;

	const char* getDescriptions() const;
	void setDescriptions(const char* descriptions);

	const char* getIngredients() const;
	void setIngredients(const char* ingredient);

	double getPrice() const;
	void setPrice(double price);
	friend ostream& operator<<(ostream& os, const MenuItem& item);
};

#endif 