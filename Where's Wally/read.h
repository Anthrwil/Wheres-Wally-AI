#pragma once
#include "inherit.h"
class read : public inherit
{
public:
	read(int width, int height, const char* filename) :inherit(width, height, filename) {};
	double* read_text(const char* filename, int sizeR, int sizeC);
};


