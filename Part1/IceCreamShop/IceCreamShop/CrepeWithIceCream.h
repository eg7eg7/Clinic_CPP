#pragma once
#ifndef _CREPEWITHICECREAM_H
#define _CREPEWITHICECREAM_H

#include <iostream>
#include "IceCreamBall.h"
#include "Crepe.h"
using namespace std;

class CrepeWithIceCream : public Crepe, public IceCreamBall
{
public:
	CrepeWithIceCream(const Crepe& crepe, const IceCreamBall& ball);
	virtual ~CrepeWithIceCream();
};
#endif
