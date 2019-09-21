#pragma once
#ifndef _CREPE_H
#define _CREPE_H

#include <iostream>

using namespace std;

enum eSpread { NUTELLA_SPREAD, NUTELLA_SPREAD_WITH_COCOS, BLUEBERRY_SPREAD, STRAWBERRY_JAM_SPREAD };
class Crepe : virtual public Dessert
{
	eSpread Spread;
public:
	Crepe(Dessert dessert, eSpread spread = eSpread(NUTELLA_SPREAD));
	virtual ~Crepe();

	eSpread getSpread() const;
	void setSpread(eSpread Spread);
};
#endif
