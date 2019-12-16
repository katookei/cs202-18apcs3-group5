#include "CBIRD.h"

bool CBIRD::stop;

void CBIRD::Draw()
{
	gotoXY(mX, mY);
	cout << char(223);
	gotoXY(mX + 1, mY);
	cout << char(220);
	gotoXY(mX + 2, mY);
	cout << char(223);
}
void CBIRD::Move(int x, int y)
{

	gotoXY(mX, mY);
	cout << " ";
	gotoXY(mX + 1, mY);
	cout << " ";
	gotoXY(mX + 2, mY);
	cout << " ";
	if (stop == false) {
		mX += 1;
	}

    Draw();
	if (mX == 113 )
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
CBIRD::CBIRD()
{
	mX = 3;
	mY = 15;
	beginSide = "Left";
	stop = false;
}
CBIRD::CBIRD(int x, int y)
{
	mX = x;
	mY = y;
	beginSide = "Left";
	stop = false;
}
CBIRD::CBIRD(int x, int y, string a)
{
	mX = x;
	mY = y;
	beginSide = a;
	stop = false;
}
CBIRD::CBIRD(string a)
{
	mX = 3;
	mY = 15;
	beginSide = a;
	stop = false;
}
void CBIRD::Tell()
{
	cout << " ";
}

void CBIRD::updateStatus()
{
	stop = !stop;
}
