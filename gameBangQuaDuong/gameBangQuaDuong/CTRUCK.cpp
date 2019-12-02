#include "CTRUCK.h"

void CTRUCK::Move() {
	gotoXY(mX, mY);
	cout << " " << endl;
	gotoXY(mX +1, mY);
	cout << " " << endl;
	mX += 1;
	Draw();
	if (mX == 114 && beginSide == "Left") {
		gotoXY(mX, mY);
		cout << " " << endl;
		gotoXY(mX + 1, mY);
		cout << " " << endl;
		mX = 3;
	}
	/*if (mX == 0 && beginSide == "Right") {
		gotoXY(mX, mY);
		cout << " " << endl;
		gotoXY(mX + 1, mY);
		cout << " " << endl;
		mX = 115;
	}*/
}

CTRUCK::CTRUCK() {
	mX = 3;
	mY = 15;
	beginSide = "Left";
}

CTRUCK::CTRUCK(int x, int y, string side) {
	mX = x;
	mY = y;
	beginSide = side;
}

CTRUCK::CTRUCK(string side) {
	mX =  3;
	mY = 25;
	beginSide = side;
}

CTRUCK::CTRUCK(int x, int y) {
	mX = x;
	mY = y;
	beginSide = "Left";
}

void CTRUCK::Draw() {
	if (beginSide == "Left") {
		gotoXY(mX, mY);
		cout << char(178) << endl;
		gotoXY(mX + 1, mY);
		cout << char(254) << endl;
	}
	if (beginSide == "Right") {
		gotoXY(mX, mY);
		cout << char(254) << endl;
		gotoXY(mX + 1, mY);
		cout << char(178) << endl;
	}
}


