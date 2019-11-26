#include "CPEOPLE.h"


void CPEOPLE::Up(int steps) {
	gotoXY(mX, mY);
	cout << " " << endl;
	mY -= steps;
	gotoXY(mX, mY);
	cout << "Y" << endl;
}

void CPEOPLE::Down(int steps) {
	gotoXY(mX, mY);
	cout << " " << endl;
	mY += steps;
	gotoXY(mX, mY);
	cout << "Y" << endl;
}

void CPEOPLE::Right(int steps) {
	gotoXY(mX, mY);
	cout << " " << endl;
	mX += steps;
	gotoXY(mX, mY);
	cout << "Y" << endl;
}

void CPEOPLE::Left(int steps) {
	gotoXY(mX, mY);
	cout << " " << endl;
	mX -= steps;
	gotoXY(mX, mY);
	cout << "Y" << endl;
}

CPEOPLE::CPEOPLE() {
	mX = 50;
	mY = 15;
	mState = true;
	gotoXY(mX, mY);
	cout << "Y" << endl;
}