#pragma once
#include "Header.h"
#include "CVEHICLE.h"
class CCAR : public CVEHICLE
{
	string beginSide;
public:
	static bool IS_STOP;
	CCAR();
	CCAR(int, int);
	CCAR(int, int, string);
	void draw();
	void Move();
};

