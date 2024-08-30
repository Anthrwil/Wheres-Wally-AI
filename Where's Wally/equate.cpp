#include "stdafx.h"
#include "equate.h"


equate::equate(int x, int y, double value)
{
	xCompare = x;
	yCompare = y;
	temp = value;
}


equate::~equate()
{
}

bool equate::operator < (equate other)
{
	if (this->temp<other.temp)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool equate::operator > (equate other)
{
	if (this->temp > other.temp)
	{
		return true;
	}
	else
	{
		return false;
	}
}
