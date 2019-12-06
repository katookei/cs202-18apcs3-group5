#include "CCAR.h"

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
}

CCAR::CCAR(int a, int b) {
	mX = a;
	mY = b;
}

CCAR::CCAR(int a, int b, string c)
{
	mX = a;
	mY = b;
	beginSide = c;
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