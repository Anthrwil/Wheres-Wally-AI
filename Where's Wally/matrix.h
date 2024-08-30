#pragma once
class matrix
{
public:
	matrix(int, int, double*);
	double* values;
	int height;
	int width;

	~matrix();

	double getValue(int x, int y);
	void setValue(int x, int y, double val);
};

