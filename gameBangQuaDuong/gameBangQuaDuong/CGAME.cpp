#include "CGAME.h"

CGAME::CGAME() {
	/*CVEHICLE* temp1,* temp2,* temp3,* temp4, * temp5, * temp6, * temp7, * temp8, * temp9;
	CANIMAL* tem1, * tem2, * tem3, * tem4;
	
	int i, k, m, l;
	i = 0 + rand() % 4;
	
	k = 0 + rand() % 4;

	if (k - i == 0)
	{
		k = 1 + rand() % 4;
	}
	m = 1 + rand() % 3;
	if (m - k == 0 || m - i == 0)
	{
		m = 1 + rand() % 4;
	}
	l = 1 + rand() % 4;
	if (l-i==0 || l-m==0 || l-k==0)
	{
		l = 1 + rand() % 4;
	}	
	temp5 = new CCAR(3, 4+i*6 + (1 + rand() % 5), "Right");
	temp6 = new CCAR(13, 4 + i * 6 + (1 + rand() % 5), "Left");
	temp7 = new CTRUCK(12, 4 + k * 6 + (1 + rand() % 5), "Left");
	temp8 = new CTRUCK(20, 4 + k * 6 + (1 + rand() % 5), "Left");
	temp9 = new CTRUCK(18, 4 + k * 6 + (1 + rand() % 5), "Left");
	

	
	vehicles.push_back(temp5);
	vehicles.push_back(temp6);
	vehicles.push_back(temp7);
	vehicles.push_back(temp8);
	vehicles.push_back(temp9);

	tem1 = new CBIRD(6, 4 + m * 6 + (1 + rand() % 5));
	tem2 = new CBIRD(8, 4 + m * 6 + (1 + rand() % 5));
	tem3 = new CDINAUSOR(5, 4 + l * 6 + (3 + rand() % 3),"Left");
	tem4 = new CDINAUSOR(100, 4 + l * 6 + (3 + rand() % 3),"Right");

	animals.push_back(tem1);
	animals.push_back(tem2);
	animals.push_back(tem3);
	animals.push_back(tem4);*/
	CVEHICLE* xe1,* xe2;
	CANIMAL* con1, * con2;
	con1 = new CBIRD(4,5);

	con2 = new CDINAUSOR(4,14);

	xe1 = new CCAR(19,20);

	xe2 = new CTRUCK(4,25);

	animals.push_back(con1);
	animals.push_back(con2);
	vehicles.push_back(xe1);
	vehicles.push_back(xe2);
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

void PrintMenu()
{
	gotoXY(50, 10);
	cout << "1. Start game";
	gotoXY(50, 11);
	cout << "2. Save game";
	gotoXY(50, 12);
	cout << "3. Load game";
	gotoXY(50, 13);
	cout << "4. Exit game";
}

bool CGAME::getIsPaused() {
	return isGamePaused;
}

