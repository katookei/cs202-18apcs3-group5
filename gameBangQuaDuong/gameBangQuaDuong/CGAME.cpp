#include "CGAME.h"

CGAME::CGAME() {
	CVEHICLE* temp1,* temp2,* temp3,* temp4, * temp5, * temp6, * temp7, * temp8, * temp9;
	
	temp1 = new CTRUCK;
	temp2 = new CTRUCK(10, 22, "Left");
	temp3 = new CTRUCK(19, 5, "Left");
	temp4 = new CTRUCK(50, 6, "Left");
	temp5 = new CTRUCK(67, 23, "Left");
	temp6 = new CTRUCK(13, 15, "Left");
	temp7 = new CTRUCK(12, 23, "Left");
	temp8 = new CTRUCK(20, 16, "Left");
	temp9 = new CTRUCK(18, 13, "Left");
	

	vehicles.push_back(temp1);
	vehicles.push_back(temp2);
	vehicles.push_back(temp3);
	vehicles.push_back(temp4);
	vehicles.push_back(temp5);
	vehicles.push_back(temp6);
	vehicles.push_back(temp7);
	vehicles.push_back(temp8);
	vehicles.push_back(temp9);

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

vector<CVEHICLE *> CGAME::getVehicle() {
	return vehicles;
}

vector<CANIMAL*> CGAME::getAnimal() {
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