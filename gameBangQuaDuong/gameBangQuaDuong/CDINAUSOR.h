#pragma once
#include "CANIMAL.h"
class CDINAUSOR :
	public CANIMAL
{
public:
	CDINAUSOR();
	CDINAUSOR(int, int);
	void draw();
	void Move(int,int);
	void Tell();
};

