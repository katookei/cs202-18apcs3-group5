#include "CCAR.h"

bool CCAR::stop;


void CCAR::draw()
{
	gotoXY(mX, mY);
	cout << char(254);
	gotoXY(mX + 1, mY);
	cout << char(178) << endl;
	gotoXY(mX + 2, mY);
	cout << char(254) << endl;
}
CCAR::CCAR() {
	mX = 0;
	mY = 25;
	stop = false;
}

CCAR::CCAR(int a, int b) {
	mX = a;
	mY = b;
	beginSide = "Left";
	stop = false;
}

CCAR::CCAR(int a, int b, string c)
{
	mX = a;
	mY = b;
	beginSide = c;
	stop = false;
}
void CCAR::Move()
{
	gotoXY(mX, mY);
	cout << " ";
	gotoXY(mX + 1, mY);
	cout << " " ;
	gotoXY(mX + 2, mY);
	cout << " ";
	if (beginSide == "Left")
	{
		if (stop == false)
		mX++;
		draw();
		if (mX + 2 == 114)
		{
		gotoXY(mX, mY);
		cout << " ";
		gotoXY(mX + 1, mY);
		cout << " ";
		gotoXY(mX + 2, mY);
		cout << " ";
		mX = 3;
		}
	}
	if (beginSide == "Right")
	{
		if (stop == false)
		mX--;
		draw();
		if (mX ==0)
		{
			gotoXY(mX, mY);
			cout << " ";
			gotoXY(mX + 1, mY);
			cout << " ";
			gotoXY(mX + 2, mY);
			cout << " ";
			mX = 100;
		}
	}
	
	
	
}


void CCAR::getStatus()
{

		stop = false;
}