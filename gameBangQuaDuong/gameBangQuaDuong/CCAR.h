#pragma once
#include "Header.h"
#include "CVEHICLE.h"
class CCAR : public CVEHICLE
{
public:
	CCAR();
	CCAR(int, int);
	void draw();
	void Move();
};

