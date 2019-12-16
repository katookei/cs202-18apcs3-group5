#include "CDINAUSOR.h"

bool CDINAUSOR::stop;


void CDINAUSOR::draw()
{
	if (beginSide == "Left")
	{
		gotoXY(mX, mY);
		cout << char(219);
		gotoXY(mX + 1, mY);
		cout << char(219) << endl;
		gotoXY(mX + 1, mY - 1);
		cout << char(219) << endl;
		gotoXY(mX + 2, mY - 1);
		cout << char(219) << endl;
		gotoXY(mX + 2, mY - 2);
		cout << char(220) << endl;
	}
	else
	{
		gotoXY(mX, mY);
		cout << char(219);
		gotoXY(mX - 1, mY);
		cout << char(219) << endl;
		gotoXY(mX - 1, mY - 1);
		cout << char(219) << endl;
		gotoXY(mX - 2, mY - 1);
		cout << char(219) << endl;
		gotoXY(mX - 2, mY - 2);
		cout << char(220) << endl;
	}
}
void CDINAUSOR::Tell()
{
	return;
}
CDINAUSOR::CDINAUSOR() {
	mX = 0;
	mY = 25;
	beginSide = "Left";
	stop = false;
}

CDINAUSOR::CDINAUSOR(int a, int b) {
	mX = a;
	mY = b;
	beginSide = "Left";
	stop = false;
}

CDINAUSOR::CDINAUSOR(int a, int b, string c)
{
	mX = a;
	mY = b;
	beginSide = c;
	stop = false;
}
void CDINAUSOR::Move(int, int)
{
	/*gotoXY(mX, mY);
	cout << " ";
	gotoXY(mX - 1, mY);
	cout << " " << endl;
	gotoXY(mX - 1, mY - 1);
	cout << " " << endl;
	gotoXY(mX - 2, mY - 1);
	cout << " " << endl;
	gotoXY(mX - 2, mY - 2);
	cout << " " << endl;*/
	if (beginSide == "Left")
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
		if (stop == false)
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
	else if (beginSide =="Right")
	{
		gotoXY(mX, mY);
		cout << " ";
		gotoXY(mX - 1, mY);
		cout << " " << endl;
		gotoXY(mX - 1, mY - 1);
		cout << " " << endl;
		gotoXY(mX - 2, mY - 1);
		cout << " " << endl;
		gotoXY(mX - 2, mY - 2);
		cout << " " << endl;
		if (stop == false)
			--mX;
		draw();
		if (mX - 2 == 0)
		{
			gotoXY(mX, mY);
			cout << " ";
			gotoXY(mX - 1, mY);
			cout << " " << endl;
			gotoXY(mX - 1, mY - 1);
			cout << " " << endl;
			gotoXY(mX - 2, mY - 1);
			cout << " " << endl;
			gotoXY(mX - 2, mY - 2);
			cout << " " << endl;
			mX = 100;
		}
	}
}

void CDINAUSOR::updateStatus()
{
	stop = !stop;
}

bool CDINAUSOR::isTouched(int x, int y) {
	if (((mX == x && mY == y) ||
		(mX + 1 == x && mY == y) ||
		(mX + 1 == x && mY == y + 1 ) ||
		(mX + 2 == x && mY == y + 1 ) ||
		(mX + 2 == x && mY == y + 2 )) &&
		beginSide == "Left"
	)
	{
		return true;
	}
	else if (((mX == x && mY == y) ||
		(mX - 1 == x && mY == y) ||
		(mX - 1 == x && mY == y + 1) ||
		(mX - 2 == x && mY == y + 1) ||
		(mX - 2 == x && mY == y + 2)) &&
		beginSide == "Right"
	)
	{
		return true;
	}
	return false;
}

int CDINAUSOR::getType() {
	return type;
}