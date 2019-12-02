#include "CDINAUSOR.h"

void CDINAUSOR::draw()
{
	gotoXY(mX, mY);
	cout << char(219);
	gotoXY(mX + 1, mY);
	cout << char(219) << endl;
	gotoXY(mX + 1, mY-1);
	cout << char(219) << endl;
	gotoXY(mX + 2, mY - 1);
	cout << char(219) << endl;
	gotoXY(mX + 2, mY - 2);
	cout << char(220) << endl;
}
void CDINAUSOR::Tell()
{
	return;
}
CDINAUSOR::CDINAUSOR() {
	mX = 0;
	mY = 25;
}

CDINAUSOR::CDINAUSOR(int a, int b) {
	mX = a;
	mY = b;
}
void CDINAUSOR::Move(int,int)
{
	gotoXY(mX, mY);
	cout << " ";
	gotoXY(mX + 1, mY);
	cout << " " << endl;
	gotoXY(mX + 1, mY - 1);
	cout << " " << endl;
	gotoXY(mX + 2, mY - 1);
	cout << " " << endl;
	gotoXY(mX + 2, mY - 2);
	cout << " " << endl;
	++mX;
	draw();
	if (mX + 2 == 114)
	{
		gotoXY(mX, mY);
		cout << " ";
		gotoXY(mX + 1, mY);
		cout << " " << endl;
		gotoXY(mX + 1, mY - 1);
		cout << " " << endl;
		gotoXY(mX + 2, mY - 1);
		cout << " " << endl;
		gotoXY(mX + 2, mY - 2);
		cout << " " << endl;
		mX = 0;
	}


}