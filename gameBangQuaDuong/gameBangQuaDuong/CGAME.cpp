#include "CGAME.h"

CGAME::CGAME() 
{
	level1Init();
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

void CGAME::levelUp()
{
	lvl += 1;
	system("cls");
	startGame();
	cn.resetPoṣ̣();
	switch (lvl)
	{
	case 2:
	{
		level2Init();
		break;
	}
	case 3:
	{
		level3Init();
		break;
	}
	case 4:
	{
		level4Init();
		break;
	}
	case 5:
	{
		level5Init();
		break;
	}
	case 6:
	{
	//	win();
		break;
	}
	}

}

void CGAME::resetGame()
{
	lvl = 1;
	system("cls");
	startGame();
	level1Init();
	cn.resetPoṣ̣();
}


void CGAME::level1Init() {
	vehicles.clear();
	animals.clear();
	CVEHICLE* temp = new CTRUCK(5, LINE1, "Left");
	CVEHICLE* temp1 = new CCAR(5, LINE2, "Left");
	CANIMAL* temp2 = new CBIRD(5, LINE3, "Left");
	CANIMAL* temp3 = new CDINAUSOR(5, LINE4, "Left");
	vehicles.push_back(temp);
	vehicles.push_back(temp1);
	animals.push_back(temp2);
	animals.push_back(temp3);
}

void CGAME::level2Init() {
	vehicles.clear();
	animals.clear();
	CVEHICLE* temp = new CTRUCK(5, LINE1, "Left");
	CVEHICLE* temp1 = new CCAR(5, LINE2, "Left");
	CANIMAL* temp2 = new CBIRD(5, LINE3, "Left");
	CANIMAL* temp3 = new CDINAUSOR(5, LINE4, "Left");
	CVEHICLE* temp4 = new CTRUCK(RIGHT - 7, LINE1, "Left");
	CVEHICLE* temp5 = new CCAR(RIGHT - 7, LINE2, "Left");
	CANIMAL* temp6 = new CBIRD(RIGHT - 7, LINE3, "Left");
	CANIMAL* temp7 = new CDINAUSOR(RIGHT - 7, LINE4, "Left");
	vehicles.push_back(temp);
	vehicles.push_back(temp1);
	vehicles.push_back(temp4);
	vehicles.push_back(temp5);
	animals.push_back(temp2);
	animals.push_back(temp3);
	animals.push_back(temp6);
	animals.push_back(temp7);
}

void CGAME::level3Init()
{
	vehicles.clear();
	animals.clear();
#pragma region VEHICLES
	CVEHICLE* temp = new CTRUCK(7, LINE1, "Left");
	CVEHICLE* temp1 = new CCAR(7, LINE2, "Left");
	CVEHICLE* temp4 = new CTRUCK(RIGHT - 7, LINE1, "Right");
	CVEHICLE* temp5 = new CCAR(RIGHT - 7, LINE2, "Right");
	CVEHICLE* Cars[5];
	CVEHICLE* Trucks[5];
	for (int i = 0; i < 5; ++i)
	{
		Cars[i] = new CCAR(5 + i * 7, LINE3 + 2, "Left");
		vehicles.push_back(Cars[i]);
	}
	for (int i = 0; i < 5; ++i)
	{
		Trucks[i] = new CTRUCK(5 + i * 7, LINE3 - 2, "Left");
		vehicles.push_back(Trucks[i]);
	}
#pragma endregion

#pragma region ANIMAL
	CANIMAL* temp2 = new CBIRD(5, LINE1, "Left");
	CANIMAL* temp3 = new CDINAUSOR(5, LINE2, "Left");
	CANIMAL* temp6 = new CBIRD(RIGHT - 7, LINE2, "Right");
	CANIMAL* temp7 = new CDINAUSOR(RIGHT - 7, LINE1, "Right");
	CANIMAL* Birds[5];
	CANIMAL* Dinausors[5];
	for (int i = 0; i < 5; ++i)
	{
		Birds[i] = new CBIRD(5 +  i * 7, LINE4 - 2 , "Left");
		animals.push_back(Birds[i]);
	}
	for (int i = 0; i < 5; ++i)
	{
		Dinausors[i] = new CDINAUSOR(RIGHT - i * 7 - 3, LINE4 + 2, "Right");
		animals.push_back(Dinausors[i]);
	}
#pragma endregion

	vehicles.push_back(temp);
	vehicles.push_back(temp1);
	vehicles.push_back(temp4);
	vehicles.push_back(temp5);
	animals.push_back(temp2);
	animals.push_back(temp3);
	animals.push_back(temp6);
	animals.push_back(temp7);
}

void CGAME::level5Init()
{
	vehicles.clear();
	animals.clear();
#pragma region VEHICLES
	CVEHICLE* Cars[15];
	CVEHICLE* Trucks[15];
	for (int i = 0; i < 5; ++i)
	{
		Cars[i] = new CCAR(5 + i * 7, LINE3 + 2, "Left");
		vehicles.push_back(Cars[i]);
		Cars[i + 5] = new CCAR(5 + i * 7, LINE1 - 2, "Left");
		vehicles.push_back(Cars[i + 5]);
		Cars[i + 10] = new CCAR((LEFT + RIGHT) / 3 + i * 7, LINE1, "Left");
		vehicles.push_back(Cars[i + 10]);
	}
	for (int i = 0; i < 5; ++i)
	{
		Trucks[i] = new CTRUCK(5 + i * 7, LINE3 - 2, "Left");
		vehicles.push_back(Trucks[i]);
		Trucks[i + 5] = new CTRUCK(RIGHT - 3, LINE1 + 2, "Right");
		vehicles.push_back(Trucks[i + 5]);
		Trucks[i + 10] = new CTRUCK((LEFT + RIGHT) * 2 / 3 - i * 7, LINE2, "Right");
		vehicles.push_back(Trucks[i + 10]);

	}
#pragma endregion

#pragma region ANIMAL
	CANIMAL* Birds[15];
	CANIMAL* Dinausors[15];
	for (int i = 0; i < 5; ++i)
	{
		Birds[i] = new CBIRD(5 + i * 7, LINE4 - 2, "Left");
		animals.push_back(Birds[i]);
		Birds[i + 5] = new CBIRD(5 + i * 7, LINE2 - 2, "Left");
		animals.push_back(Birds[i + 5]);
		Birds[i + 10] = new CBIRD((LEFT + RIGHT) / 3 + i * 7, LINE3, "Left");
		animals.push_back(Birds[i + 10]);
	}
	for (int i = 0; i < 5; ++i)
	{
		Dinausors[i] = new CDINAUSOR(RIGHT - i * 7 - 3, LINE4 + 2, "Right");
		animals.push_back(Dinausors[i]);
		Dinausors[i + 5] = new CDINAUSOR(RIGHT - i * 7 - 3, LINE2 + 2, "Right");
		animals.push_back(Dinausors[i + 5]);
		Dinausors[i + 10] = new CDINAUSOR(RIGHT - i * 7 - 3, LINE4, "Right");
		animals.push_back(Dinausors[i + 10]);
	}
#pragma endregion
}

void CGAME::level4Init()
{
	vehicles.clear();
	animals.clear();
#pragma region VEHICLES
	CVEHICLE* Cars[10];
	CVEHICLE* Trucks[10];
	for (int i = 0; i < 5; ++i)
	{
		Cars[i] = new CCAR(5 + i * 7, LINE3 + 2, "Left");
		vehicles.push_back(Cars[i]);
		Cars[i + 5] = new CCAR(5 + i * 7, LINE1 - 2, "Left");
		vehicles.push_back(Cars[i + 5]);
	}
	for (int i = 0; i < 5; ++i)
	{
		Trucks[i] = new CTRUCK(5 + i * 7, LINE3 - 2, "Left");
		vehicles.push_back(Trucks[i]);
		Trucks[i + 5] = new CTRUCK(RIGHT - 3, LINE1 + 2, "Right");
		vehicles.push_back(Trucks[i+5]);
	}
#pragma endregion

#pragma region ANIMAL
	CANIMAL* Birds[10];
	CANIMAL* Dinausors[10];
	for (int i = 0; i < 5; ++i)
	{
		Birds[i] = new CBIRD(5 + i * 7, LINE4 - 2, "Left");
		animals.push_back(Birds[i]);
		Birds[i + 5] = new CBIRD(5 + i * 7, LINE2 - 2, "Left");
		animals.push_back(Birds[i + 5]);
	}
	for (int i = 0; i < 5; ++i)
	{
		Dinausors[i] = new CDINAUSOR(RIGHT - i * 7 - 3, LINE4 + 2, "Right");
		animals.push_back(Dinausors[i]);
		Dinausors[i + 5] = new CDINAUSOR(RIGHT - i * 7 - 3, LINE2 + 2, "Right");
		animals.push_back(Dinausors[i + 5]);
	}
#pragma endregion
}

void printMenuAfterDead()
{
	system("cls");
	gotoXY(45, 9);
	cout << "You've died choose your option";
	gotoXY(50, 10);
	cout << "1. Restart";
	gotoXY(50, 11);
	cout << "2. Load game";
	gotoXY(50, 12);
	cout << "3. Exit game";
}