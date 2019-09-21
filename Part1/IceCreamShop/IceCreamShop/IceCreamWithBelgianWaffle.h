#pragma once
#ifndef _ICECREAMWITHBELGIANWAFFLE_H
#define _ICECREAMWITHBELGIANWAFFLE_H

#include <iostream>
#include "IceCreamWithBelgianWaffle.h"
#include "IceCreamBall.h"
#include "BelgianWaffle.h"
using namespace std;

class IceCreamWithBelgianWaffle : public IceCreamBall, public BelgianWaffle
{
public:
	IceCreamWithBelgianWaffle(const IceCreamBall& iceCream, const BelgianWaffle& waffle);
	virtual ~IceCreamWithBelgianWaffle();
};
#endif
#pragma once
