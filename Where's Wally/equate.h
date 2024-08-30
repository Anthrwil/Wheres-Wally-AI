#pragma once
class equate
{
public:
	equate(int x, int y, double value);

	int xCompare;
	int yCompare;
	double temp;

	~equate();

	bool operator<(equate other);
	bool operator>(equate other);
};

