#include "CGAME.h"

CGAME::CGAME() {
	CVEHICLE* temp1,* temp2,* temp3,* temp4, * temp5, * temp6, * temp7, * temp8, * temp9;
	CANIMAL* tem1, * tem2, * tem3, * tem4;
	
	/*tem1 = new CDINAUSOR(100, 5, "Right");
	tem2= new CDINAUSOR(3, 10, "Left");*/
	temp5 = new CCAR(3, 23, "Right");
	temp6 = new CTRUCK(13, 15, "Left");
	temp7 = new CTRUCK(12, 23, "Left");
	temp8 = new CTRUCK(20, 16, "Left");
	temp9 = new CTRUCK(18, 13, "Left");
	

	
	vehicles.push_back(temp5);
	vehicles.push_back(temp6);
	vehicles.push_back(temp7);
	vehicles.push_back(temp8);
	vehicles.push_back(temp9);

	tem1 = new CBIRD(6, 7);
	tem2 = new CBIRD(8, 20);
	tem3 = new CDINAUSOR(5, 10,"Left");
	tem4 = new CDINAUSOR(100, 7,"Right");

	animals.push_back(tem1);
	animals.push_back(tem2);
	animals.push_back(tem3);
	animals.push_back(tem4);
}

void CGAME::updatePosPeople(int mov) {
	switch (mov)
	{
	    case 80: {
	    	cn.Down(1);
	    	break;
	    }
	    case 72: {
	    	cn.Up(1);
	    	break;
	    }
	    case 75: {
	    	cn.Left(1);
	    	break;
	    }
	    case 77: {
	    	cn.Right(1);
	    	break;
	    }
		default: {
			break;
		}
    }
}
void CGAME::updatePosAnimal()
{
	for (int i = 0; i < animals.size(); i++)
	{
		animals[i]->Move(1, 1);
	}
}
CGAME::~CGAME() {
	//...
}

void CGAME::startGame() 
{
	drawGame();
}

CPEOPLE CGAME::getPeople() {
	return cn;
}

void CGAME::updatePosVehicle() {
	for (int i = 0; i < vehicles.size(); i++)
	{ 
		vehicles[i]->Move();
	}
}

vector<CVEHICLE*>& CGAME::getVehicle() {
	return vehicles;
}

vector<CANIMAL*>& CGAME::getAnimal() {
	return animals;
}

void CGAME::drawGame()
{
	// Ve~  thanh tren cung
	gotoXY(2, 4);
	cout << char(218);
	gotoXY(116, 4);
	cout << char(191);

	for (int i = 3; i < 116; i++)
	{
		gotoXY(i, 4);
		cout << char(196);
	}
	// Ve~ hai thanh ben canh
	for (int i = 5; i < 28; i++)
	{
		gotoXY(2, i);
		cout << char(179);
	}
	for (int i = 5; i < 28; i++)
	{
		gotoXY(116, i);
		cout << char(179);
	}
	// Ve~ thanh duoi cung
	for (int i = 3; i < 116; i++)
	{
		gotoXY(i, 28);
		cout << char(196);
	}
	gotoXY(2, 28);
	cout << char(192);
	gotoXY(116, 28);
	cout << char(217);

	// Ve~ lan duong
	for (int i = 1; i < 4; i++)
	{
		gotoXY(2, 4 + i * 6);
		cout << char(198);
	}
	for (int i = 1; i < 4; i++)
	{
		gotoXY(116, 4 + i * 6);
		cout << char(181);
	}
	for (int i = 1; i < 4; i++)
	{
		for (int k = 3; k < 116; k++)
		{
			gotoXY(k, 4 + i * 6);
			cout << char(205);
		}
	}
}