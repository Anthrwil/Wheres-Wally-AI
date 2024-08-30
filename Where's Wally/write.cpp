#include "stdafx.h"
#include <sstream> 
#include <iostream> 
#include <fstream> 
#include <istream>
#include "write.h"
#include "matrix.h"

using namespace std;

void write::write_pgm(const char* filename) {
	int i, j;
	unsigned char *image;
	ofstream myfile;

	image = (unsigned char *) new unsigned char[w*h];

	for (i = 0; i<w*h; i++)
		image[i] = (unsigned char)Matrix->values[i];

	myfile.open(filename, ios::out | ios::binary | ios::trunc);

	if (!myfile) {
		cout << "Can't open file: " << filename << endl;
		exit(1);
	}

	myfile << "P5" << endl;
	myfile << w << " " << h << endl;
	myfile << 255 << endl;

	myfile.write(reinterpret_cast<char *>(image), (w*h) * sizeof(unsigned char));

	if (myfile.fail()) {
		cout << "Can't write image " << filename << endl;
		exit(0);
	}
	myfile.close();
	delete[] image;
}

