#include "stdafx.h"
#include "inherit.h"

inherit::inherit(int width, int height, const char* filename)
{
	w = width;
	h = height;
	Matrix = new matrix(width, height, read_text(filename, width, height));
}
inherit::~inherit()
{
	delete Matrix;
}

double* inherit::read_text(const char* filename, int sizeR, int sizeC) {
	double* data = new double[sizeR*sizeC];
	int i = 0;
	std::ifstream myfile(filename);
	if (myfile.is_open()) {
		while (myfile.good()) {
			if (i>sizeR*sizeC - 1) break;
			myfile >> *(data + i);
			// cout << *(data+i) << ' '; // This line display the converted data on the screen, you may comment it out. 
			i++;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
	//cout << i;
	return data;
}
