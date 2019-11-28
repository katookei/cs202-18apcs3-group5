#include "CTRUCK.h"

void CTRUCK::Move() {
	gotoXY(mX, mY);
	cout << " " << endl;
	gotoXY(mX +1, mY);
	cout << " " << endl;
	mX += 1;
	Draw();
	if (mX == 100 && beginSide == "Left") {
		gotoXY(mX, mY);
		cout << " " << endl;
		gotoXY(mX + 1, mY);
		cout << " " << endl;
		mX = 0;
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
	mX = 0;
	mY = 25;
	beginSide = "Left";
}

CTRUCK::CTRUCK(int x, int y, string side) {
	mX = x;
	mY = y;
	beginSide = side;
}

CTRUCK::CTRUCK(string side) {
	mX = 0;
	mY = 25;
	beginSide = side;
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


