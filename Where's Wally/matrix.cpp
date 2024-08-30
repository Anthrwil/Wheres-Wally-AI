#include "stdafx.h"
#include "matrix.h"

matrix::matrix(int w, int h, double*vals)
{
	width = w;
	height = h;
	values = vals;
}

matrix::~matrix()
{
	delete values;
}

double matrix::getValue(int x, int y) 
{
	return values[(width*y) + x];
}

void matrix::setValue(int x, int y, double val) 
{
	values[(width*y) + x] = val;
}
