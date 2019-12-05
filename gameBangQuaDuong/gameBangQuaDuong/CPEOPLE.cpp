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

bool CPEOPLE::isImpact(const vector<CVEHICLE*>& vehicles) {
	for (int i = 0; i < vehicles.size(); i++)
	{
		if (vehicles[i]->getMX() == mX && vehicles[i]->getMY() == mY) {
			
			return true;
		}
	}
	return false;
}

bool CPEOPLE::isImpact(const vector<CANIMAL*> & animals) {
	for (int i = 0; i < animals.size(); i++)
	{
		if (animals[i]->getMX() == mX && animals[i]->getMY() == mY) {
			return true;
		}
	}
	return false;
}

CPEOPLE::CPEOPLE() {
	mX = 50;
	mY = 2;
	mState = true;
	gotoXY(mX, mY);
	cout << "Y" << endl;
}

int CPEOPLE::getX()
{
	return mX;
}

int CPEOPLE::getY()
{
	return mY;
}