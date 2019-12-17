#include "CPEOPLE.h"


void CPEOPLE::Up(int steps) {
	PlaySound("step.wav", NULL, SND_ASYNC);
	gotoXY(mX, mY);
	cout << " " << endl;
	mY -= steps;
	gotoXY(mX, mY);
	cout << "Y" << endl;
}

void CPEOPLE::Down(int steps) {
	PlaySound("step.wav", NULL, SND_ASYNC);
	gotoXY(mX, mY);
	cout << " " << endl;
	mY += steps;
	gotoXY(mX, mY);
	cout << "Y" << endl;
}

void CPEOPLE::Right(int steps) {
	PlaySound("step.wav", NULL, SND_ASYNC);
	gotoXY(mX, mY);
	cout << " " << endl;
	mX += steps;
	gotoXY(mX, mY);
	cout << "Y" << endl;
}

void CPEOPLE::Left(int steps) {
	PlaySound("step.wav", NULL, SND_ASYNC);
	gotoXY(mX, mY);
	cout << " " << endl;
	mX -= steps;
	gotoXY(mX, mY);
	cout << "Y" << endl;
}

bool CPEOPLE::isImpact(const vector<CVEHICLE*>& vehicles) {
	for (int i = 0; i < vehicles.size(); i++)
	{
		if (vehicles[i]->isTouched(mX, mY)) {
			return true;
		}
	}
	return false;
}

bool CPEOPLE::isImpact(const vector<CANIMAL*> & animals) {
	for (int i = 0; i < animals.size(); i++)
	{
		if (animals[i]->isTouched(mX, mY)) {
			return true;
		}
	}
	return false;
}

CPEOPLE::CPEOPLE() {
	mX = 60;
	mY = TOP;
	mState = true;
}

CPEOPLE::CPEOPLE(int x, int y) {
	mX = x;
	mY = y;
	mState = true;
}

int CPEOPLE::getX()
{
	return mX;
}

int CPEOPLE::getY()
{
	return mY;
}

void CPEOPLE::setX(int x)
{
	mX = x;
}

void CPEOPLE::setY(int y)
{
	mY = y;
}

bool CPEOPLE::isFinish() {
	bool res;
	mY == BOTTOM ? res = true : res = false;
	return res;
}

void CPEOPLE::resetPoṣ̣() {
	gotoXY(mX, mY);
	cout << char(196);
	mX = 60;
	mY = TOP;
}

bool CPEOPLE::isDead() {
	gotoXY(50, 14);
	cout << "GAME OVER!!";
	PlaySound("die.wav", NULL, SND_FILENAME);
	return mState;
}

void CPEOPLE::draw() {
	gotoXY(mX, mY);
	cout << "Y";
}