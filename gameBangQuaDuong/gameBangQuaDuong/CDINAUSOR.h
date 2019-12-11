#pragma once
#include "CANIMAL.h"
class CDINAUSOR :
	public CANIMAL
{
	string beginSide;
public:
	CDINAUSOR();
	CDINAUSOR(int, int);
	CDINAUSOR(int, int, string);
	void draw();
	void Move(int,int);
	void Tell();
};

