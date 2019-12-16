#pragma once
#include "CVEHICLE.h"
#include "Header.h"
class CTRUCK : public CVEHICLE
{
	string beginSide;
public:
	static bool stop;
	void Move();
	void Draw();
	CTRUCK();
	CTRUCK(string);
	CTRUCK(int, int);
	CTRUCK(int, int, string);
	void updateStatus();
	bool isTouched(int x, int y);
	int getType();
};

