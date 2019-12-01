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
void CCAR::Move()
{
	gotoXY(mX, mY);
	cout << " ";
	gotoXY(mX + 1, mY);
	cout << " " ;
	gotoXY(mX + 2, mY);
	cout << " ";
	++mX;
	draw();
	if (mX + 2 == 115)
	{
		gotoXY(mX, mY);
		cout << " ";
		gotoXY(mX + 1, mY);
		cout << " ";
		gotoXY(mX + 2, mY);
		cout << " ";
		mX = 0;
	}
	
	
}