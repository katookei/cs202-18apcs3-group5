#pragma once
#include "Header.h"
#include "CVEHICLE.h"
class CCAR : public CVEHICLE
{
	string beginSide;
public:
	CCAR();
	CCAR(int, int);
	CCAR(int, int, string);
	void draw();
	void Move();
};

