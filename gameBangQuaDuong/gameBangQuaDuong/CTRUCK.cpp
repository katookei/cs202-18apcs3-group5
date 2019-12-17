#include "CTRUCK.h"

bool CTRUCK::stop;

void CTRUCK::Move() {
	gotoXY(mX, mY);
	cout << " " << endl;
	gotoXY(mX + 1, mY);
	cout << " " << endl;
	if (beginSide == "Left") {
		if (!stop)
			mX += 1;
		Draw();
		if (mX == 112) {
			gotoXY(mX, mY);
			cout << " " << endl;
			gotoXY(mX + 1, mY);
			cout << " " << endl;
			gotoXY(mX + 2, mY);
			cout << " " << endl;
			gotoXY(mX + 3, mY);
			cout << " " << endl;
			mX = 3;
		}
	}
	if (beginSide == "Right") {
		if (!stop)
			mX += 1;
		Draw();
		if (mX == 4) {
			gotoXY(mX, mY);
			cout << " " << endl;
			gotoXY(mX + 1, mY);
			cout << " " << endl;
			mX = 115;
		}
	}
}

CTRUCK::CTRUCK() {
	mX = 3;
	mY = 15;
	beginSide = "Left";
	stop = false;
}

CTRUCK::CTRUCK(int x, int y, string side) {
	mX = x;
	mY = y;
	beginSide = side;
	stop = false;
}

CTRUCK::CTRUCK(string side) {
	mX = 3;
	mY = 25;
	beginSide = side;
	stop = false;
}

CTRUCK::CTRUCK(int x, int y) {
	mX = x;
	mY = y;
	beginSide = "Left";
	stop = false;
}

void CTRUCK::Draw() {
	if (beginSide == "Left") {
		gotoXY(mX, mY);
		cout << char(219) << endl;
		gotoXY(mX + 1, mY);
		cout << char(16) << endl;
		gotoXY(mX + 2, mY);
		cout << char(219) << endl;
		gotoXY(mX + 3, mY);
		cout << char(175) << endl;
	}
	if (beginSide == "Right") {
		gotoXY(mX, mY);
		cout << char(219) << endl;
		gotoXY(mX - 1, mY);
		cout << char(16) << endl;
		gotoXY(mX -2, mY);
		cout << char(219) << endl;
		gotoXY(mX - 3, mY);
		cout << char(175) << endl;
	}
}

void CTRUCK::updateStatus()
{
	stop = !stop;
}

bool CTRUCK::isTouched(int x, int y) {
	if (((mX == x && mY == y ) ||
		(mX + 1 == x && mY == y) || (mX +2  == x && mY == y) || (mX + 3== x && mY == y)) && (beginSide == "Left"))
	{

		return true;
	}
	if (((mX == x && mY == y) ||
		(mX - 1 == x && mY == y) || (mX - 2 == x && mY == y) || (mX - 3 == x && mY == y)) && (beginSide == "Right"))
	{

		return true;
	}
	return false;
}

int CTRUCK::getType() {
	return type;
}