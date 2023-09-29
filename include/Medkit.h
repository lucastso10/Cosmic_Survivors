//#pragma once
#ifndef _MEDKIT_H
#define _MEDKIT_H

#include "Object.h"

class Medkit : public Object
{

private:
	float amountHealed;

public:
	float getAmountHealed();

};

#endif