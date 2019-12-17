#pragma once
#include "CANIMAL.h"
#include "Header.h"
#include <string>

class CBIRD :
	public CANIMAL
{
	string beginSide;
public:
	static bool stop;
	void Move(int x, int y);
	void Tell();
	void Draw();
	CBIRD();
	CBIRD(int x, int y);
	CBIRD(string a);
	CBIRD(int x, int y, string a);
	void updateStatus();
	bool isTouched(int x, int y);
	int getType();
	int type = 2;
};

