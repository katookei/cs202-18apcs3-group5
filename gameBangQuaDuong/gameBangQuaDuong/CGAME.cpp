#include "CGAME.h"

CGAME::CGAME() {
	CVEHICLE* temp1,* temp2,* temp3,* temp4, * temp5, * temp6, * temp7, * temp8, * temp9;
	CANIMAL* tem1, * tem2, * tem3, * tem4;
	
	
	temp5 = new CTRUCK(4, 23, "Left");
	temp6 = new CTRUCK(13, 21, "Left");
	temp7 = new CTRUCK(12, 25, "Left");
	temp8 = new CTRUCK(20, 13, "Left");
	temp9 = new CTRUCK(18, 13, "Left");
	

	
	vehicles.push_back(temp5);
	vehicles.push_back(temp6);
	vehicles.push_back(temp7);
	vehicles.push_back(temp8);
	vehicles.push_back(temp9);

	tem1 = new CBIRD(6, 5);
	tem2 = new CBIRD(8, 23);
	tem3 = new CDINAUSOR(6, 19);
	tem4 = new CDINAUSOR(15, 13);

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
			for (int i = 1; i < 4; ++i)
				if (getPeople().getY() - 1 == 4 + i * 6)
				{
					gotoXY(getPeople().getX(), getPeople().getY() - 1);
					cout << char(205);
				}
			if ((getPeople().getX() == 2 || getPeople().getX() == 116) && getPeople().getY() > 4 && getPeople().getY() < 26)
			{
				gotoXY(getPeople().getX(), getPeople().getY() - 1);
				cout << char(179);
			}
			if (getPeople().getY() - 1 == 4)
			{
				gotoXY(getPeople().getX(), getPeople().getY() - 1);
				cout << char(196);
			}
	    	break;
	    }
	    case 72: {
	    	cn.Up(1);
			for (int i = 1; i < 4; ++i)
				if (getPeople().getY() + 1 == 4 + i * 6)
				{
					gotoXY(getPeople().getX(), getPeople().getY() + 1);
					cout << char(205);
				}
			if ((getPeople().getX() == 2 || getPeople().getX() == 116) && getPeople().getY() > 4 && getPeople().getY() < 26)
			{
				gotoXY(getPeople().getX(), getPeople().getY() + 1);
				cout << char(179);
			}
			if (getPeople().getY() + 1 == 28)
			{
				gotoXY(getPeople().getX(), getPeople().getY() + 1);
				cout << char(196);
			}
	    	break;
	    }
	    case 75: {
	    	cn.Left(1);
			for (int i = 1; i < 4; ++i)
				if (getPeople().getY() == 4 + i * 6)
				{
					gotoXY(getPeople().getX() + 1, getPeople().getY());
					cout << char(205);
				}
			if ((getPeople().getY() == 28 || getPeople().getY() == 4) && getPeople().getX() > 2 && getPeople().getX() < 116)
			{
				gotoXY(getPeople().getX() + 1, getPeople().getY());
				cout << char(196);
			}
			if (getPeople().getX() + 1 == 116 && getPeople().getX() > 2 && getPeople().getX() < 116)
			{
				gotoXY(getPeople().getX() + 1, getPeople().getY());
				cout << char(179);
			}
	    	break;
	    }
	    case 77: {
	    	cn.Right(1);
			for (int i = 1; i < 4; ++i)
				if (getPeople().getY() == 4 + i * 6)
				{
					gotoXY(getPeople().getX() - 1, getPeople().getY());
					cout << char(205);
				}
			if ((getPeople().getY() == 28 || getPeople().getY() == 4) && getPeople().getX() > 2 && getPeople().getX() < 116)
			{
				gotoXY(getPeople().getX() - 1, getPeople().getY());
				cout << char(196);
			}
			if (getPeople().getX() - 1 == 2)
			{
				gotoXY(getPeople().getX() - 1, getPeople().getY());
				cout << char(179);
			}
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

void CGAME::pauseGame() {
	isGamePaused = true;
	printPauseGameMenu();
}

void CGAME::erasePasueGameMenu() {
	gotoXY(50, 10);
	cout << char(205) << char(205) << char(205)
		 << char(205) << char(205) << char(205) 
		 << char(205) << char(205) << char(205)
		 << char(205) << char(205) << char(205) << endl;
	gotoXY(50, 11);
	cout << "         " << endl;
	gotoXY(50, 12);
	cout << "            " << endl;
	gotoXY(50, 13);
	cout << "            " << endl;
	gotoXY(50, 14);
	cout << "               " << endl;
	// give time for window cursor to move to the right coordinate
}


void CGAME::printPauseGameMenu() {
	Sleep(100);
	// give time for window cursor to move to the right coordinate
	gotoXY(50, 10);
	cout << "game paused" << endl;
	gotoXY(50, 11);
	cout << "Resume(R)" << endl;
	gotoXY(50, 12);
	cout << "Save game(S)" << endl;
	gotoXY(50, 13);
	cout << "Quit game(Q)" << endl;
	while (1) {
		bool pauseFlag = true;
		char temp = toupper(_getch());
		gotoXY(50, 14);
		cout << "You pressed: " << temp;
		switch (temp)
		{
		case 13: {
			pauseFlag = false;
			erasePasueGameMenu();
			resumeGame();
			break;
		}
		default:
			break;
		}
		if (!pauseFlag) {
			break;
		}
	}
}

void CGAME::resumeGame() {
	isGamePaused = false;
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

bool CGAME::getIsPaused() {
	return isGamePaused;
}