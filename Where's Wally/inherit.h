#pragma once
#include <iostream>
#include <fstream>
#include "matrix.h"
class inherit
{
public:
	inherit(int width, int height, const char* filename);
	matrix* Matrix;
	int w;
	int h;

	~inherit();
private:
	double* read_text(const char* filename, int sizeR, int sizeC);
};

