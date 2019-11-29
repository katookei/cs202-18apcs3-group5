#pragma once
#include "Header.h"
#include "CVEHICLE.h"
class CCAR :
	public CVEHICLE
{
	int x, y;
public:
	CCAR();
	CCAR(int, int);
	void draw();
	void Move();
};

