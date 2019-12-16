#include "CGAME.h"

CGAME::CGAME(int n) 
{
	CVEHICLE** Vehicles[5];
	CANIMAL** Animals[5];
	for (int i = 0; i < 5; ++i)
	{
		Vehicles[i] = new  CVEHICLE * [n * 6];
		Animals[i] = new  CANIMAL * [n * 6];
	}
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < n * 3; ++j)
		{
			Vehicles[i][j] = new CCAR(i * 5,TOP + j*2+1, "Left");
			Vehicles[i][j + n * 3] = new CTRUCK(i * 5,TOP + (j+n*3)*2+1, "Left");
			Animals[i][j] = new CBIRD(i * 5,TOP + j*2, "Right");
			Animals[i][j + n * 3] = new CDINAUSOR(i * 5,TOP + (j+n*3)*2, "Right");
		}
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < n * 6; ++j)
		{
			vehicles.push_back(Vehicles[i][j]);
			animals.push_back(Animals[i][j]);
		}
}

void CGAME::updatePosPeople(int mov) {
	switch (mov)
	{
	    case 80: {
			if (getPeople().getY() < BOTTOM)
			{
				cn.Down(1);
				for (int i = 1; i < TOP; ++i)
					if (getPeople().getY() - 1 == TOP + i * 6)
					{
						gotoXY(getPeople().getX(), getPeople().getY() - 1);
						cout << char(205);
					}
				if ((getPeople().getX() == LEFT || getPeople().getX() == RIGHT) && getPeople().getY() > TOP && getPeople().getY() < BOTTOM)
				{
					gotoXY(getPeople().getX(), getPeople().getY() - 1);
					cout << char(179);
				}
				if (getPeople().getY() - 1 == TOP)
				{
					gotoXY(getPeople().getX(), getPeople().getY() - 1);
					cout << char(196);
				}
			}
	    	break;
	    }
	    case 72: {
			if (getPeople().getY() > TOP)
			{
				cn.Up(1);
				for (int i = 1; i < TOP; ++i)
					if (getPeople().getY() + 1 == TOP + i * 6)
					{
						gotoXY(getPeople().getX(), getPeople().getY() + 1);
						cout << char(205);
					}
				if ((getPeople().getX() == LEFT || getPeople().getX() == RIGHT) && getPeople().getY() > TOP && getPeople().getY() < BOTTOM)
				{
					gotoXY(getPeople().getX(), getPeople().getY() + 1);
					cout << char(179);
				}
				if (getPeople().getY() + 1 == BOTTOM)
				{
					gotoXY(getPeople().getX(), getPeople().getY() + 1);
					cout << char(196);
				}
			}
	    	break;
	    }
	    case 75: {
			if (getPeople().getX() > LEFT)
			{
				cn.Left(1);
				for (int i = 1; i < TOP; ++i)
					if (getPeople().getY() == TOP + i * 6)
					{
						gotoXY(getPeople().getX() + 1, getPeople().getY());
						cout << char(205);
					}
				if ((getPeople().getY() == BOTTOM || getPeople().getY() == TOP) && getPeople().getX() > LEFT && getPeople().getX() < RIGHT)
				{
					gotoXY(getPeople().getX() + 1, getPeople().getY());
					cout << char(196);
				}
				if (getPeople().getX() + 1 == RIGHT && getPeople().getX() > LEFT && getPeople().getX() < RIGHT)
				{
					gotoXY(getPeople().getX() + 1, getPeople().getY());
					cout << char(179);
				}
			}
	    	break;
	    }
	    case 77: {
			if (getPeople().getX() < RIGHT)
			{ 
	    	cn.Right(1);
			for (int i = 1; i < TOP; ++i)
				if (getPeople().getY() == TOP + i * 6)
				{
					gotoXY(getPeople().getX() - 1, getPeople().getY());
					cout << char(205);
				}
			if ((getPeople().getY() == BOTTOM || getPeople().getY() == TOP) && getPeople().getX() > 2 && getPeople().getX() < RIGHT)
			{
				gotoXY(getPeople().getX() - 1, getPeople().getY());
				cout << char(196);
			}
			if (getPeople().getX() - 1 == LEFT)
			{
				gotoXY(getPeople().getX() - 1, getPeople().getY());
				cout << char(179);
			}
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
	gotoXY(LEFT, TOP);
	cout << char(218);
	gotoXY(RIGHT, TOP);
	cout << char(191);

	for (int i = 3; i < RIGHT; i++)
	{
		gotoXY(i, TOP);
		cout << char(196);
	}
	// Ve~ hai thanh ben canh
	for (int i = 5; i < BOTTOM; i++)
	{
		gotoXY(LEFT, i);
		cout << char(179);
	}
	for (int i = 5; i < BOTTOM; i++)
	{
		gotoXY(RIGHT, i);
		cout << char(179);
	}
	// Ve~ thanh duoi cung
	for (int i = 3; i < RIGHT; i++)
	{
		gotoXY(i, BOTTOM);
		cout << char(196);
	}
	gotoXY(LEFT, BOTTOM);
	cout << char(192);
	gotoXY(RIGHT, BOTTOM);
	cout << char(217);

	// Ve~ lan duong
	for (int i = 1; i < 4; i++)
	{
		gotoXY(LEFT, TOP + i * 6);
		cout << char(198);
	}
	for (int i = 1; i < 4; i++)
	{
		gotoXY(RIGHT, TOP + i * 6);
		cout << char(181);
	}
	for (int i = 1; i < 4; i++)
	{
		for (int k = 3; k < RIGHT; k++)
		{
			gotoXY(k, TOP + i * 6);
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

bool CGAME::isFinish()
{
	if (getPeople().getY() == BOTTOM)
		return true;
	else
		return false;
}