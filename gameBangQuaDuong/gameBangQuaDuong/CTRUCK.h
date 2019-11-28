#pragma once
#include "CVEHICLE.h"
#include "Header.h"
class CTRUCK : public CVEHICLE
{
	int mX, mY;
	string beginSide;
public:
	void Move();
	void Draw();
	CTRUCK();
	CTRUCK(string);
	CTRUCK(int, int, string);
};

