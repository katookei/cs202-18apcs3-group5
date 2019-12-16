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
	cn.draw();
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
		int temp = toupper(_getch());
		gotoXY(50, 14);
		cout << "You pressed: " << temp;
		switch (temp)
		{
		case 82: {
			pauseFlag = false;
			erasePasueGameMenu();
			resumeGame();
			break;
		}
		case 83: {
			pauseFlag = false;
			saveGame();
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
	cout << "2. Load game";
	gotoXY(50, 12);
	cout << "3. Exit game";
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
	level2Init();
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
	cn.draw();
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
	cn.draw();
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

void CGAME::saveGame() {
	string temp;
	ofstream fout;
	gotoXY(50, 14);
	cout << "input save name:";
	cin >> temp;
	fout.open(temp + ".txt", ios::trunc);
	fout << lvl;
	gotoXY(50, 20);
	cout << "Game saved!" << endl;
	Sleep(1000);
	system("cls");
	drawGame();
	cn.draw();
	resumeGame();

}


void CGAME::loadGame() {
    string temp;
    ifstream fin;
    gotoXY(50, 14);
    cout << "input load name:";
    cin >> temp;
    fin.open(temp + ".txt");
	while (!fin.is_open()) {
		gotoXY(50, 14);
		cout << "                                                                                                  " << endl;
		gotoXY(50, 14);
		cout << "No file with inputed name, please input again:" << endl;
		gotoXY(96, 14);
		cin >> temp;
		fin.open(temp + ".txt");
	}
	fin >> lvl;
	level2Init();
}



