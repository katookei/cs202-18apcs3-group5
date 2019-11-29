#include "CCAR.h"

void CCAR::draw()
{
	gotoXY(x, y);
	cout << char(254);
	gotoXY(x+1, y);
	cout << char(178) << endl;
	gotoXY(x + 2, y);
	cout << char(254) << endl;
}
CCAR::CCAR() {
	x= 0;
	y= 25;
}

CCAR::CCAR(int a, int b) {
	x = a;
	y = b;
}
void CCAR::Move()
{
	gotoXY(x, y);
	cout << " ";
	gotoXY(x + 1, y);
	cout << " " ;
	gotoXY(x + 2, y);
	cout << " ";
	x++;
	draw();
	if (x+2 == 115)
	{
		gotoXY(x, y);
		cout << " ";
		gotoXY(x + 1, y);
		cout << " ";
		gotoXY(x + 2, y);
		cout << " ";
		x = 0;
	}
	
	
}