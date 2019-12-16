#pragma once
#include "CVEHICLE.h"
#include "Header.h"
class CTRUCK : public CVEHICLE
{
	string beginSide;
public:
	static bool IS_STOP;
	void Move();
	void Draw();
	CTRUCK();
	CTRUCK(string);
	CTRUCK(int, int);
	CTRUCK(int, int, string);
};

