#pragma once
#include "CANIMAL.h"
class CDINAUSOR :
	public CANIMAL
{
	string beginSide;
public:
	static bool stop;
	CDINAUSOR();
	CDINAUSOR(int, int);
	CDINAUSOR(int, int, string);
	void draw();
	void Move(int, int);
	void Tell();
	void updateStatus();
	bool isTouched(int x,int y);
	int getType();
	int type = 3;
};

