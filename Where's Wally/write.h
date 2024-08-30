#pragma once
#include <iostream>
#include <ostream>
#include "inherit.h"
class write : public inherit
{
public: 
	write(int width, int height, const char* filename) :inherit(width, height, filename) {};
	void write_pgm(const char* filename);
};

