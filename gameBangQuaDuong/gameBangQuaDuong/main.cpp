#include"CGAME.h"
using namespace std;

bool IS_RUNNING = true;
int KEY = NULL;
CGAME newGAME;
mutex g_i_mutex;
bool IS_LOSE = false;

void menuScreen(int n);

void exitGame(thread *t1) {
	system("cls");
	IS_RUNNING = false;
	t1->join();
}



void ThreadFunc1() {
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	int lightcolor[2] = { 12,10 };
	int light = 1;
	int count = 0;
	int type = 0;
	while (IS_RUNNING) {
		if (!newGAME.getIsPaused()) {
			gotoXY(2, 3);
			cout << "level " << newGAME.lvl;
			if (KEY != NULL) {
				newGAME.updatePosPeople(KEY);
				KEY = NULL;
			}
			newGAME.updatePosVehicle();
			newGAME.updatePosAnimal();
			if (count == 0)
			{  
				light = !light;
				for (int i = 0; i < newGAME.getVehicle().size(); i++)
				{
					if (type != newGAME.getVehicle()[i]->getType()) {
						type = newGAME.getVehicle()[i]->getType();
						newGAME.getVehicle()[i]->updateStatus();
					}
				}
			    
				for (int j = 1; j < 5; j++)
				{
					SetConsoleTextAttribute(hConsoleColor, lightcolor[light]);
					gotoXY(115, 2 + j * 6);
					cout << char(219);
					SetConsoleTextAttribute(hConsoleColor, 15);
					gotoXY(115, 3 + j * 6);
					cout << char(219) << endl;
					gotoXY(115, 4 + j * 6);
					cout << char(223) << endl;
				}
				count = 100;
			}
			count -= 1;
			if (newGAME.getPeople().isImpact(newGAME.getVehicle()) ||
				newGAME.getPeople().isImpact(newGAME.getAnimal())) {
				IS_LOSE = true;
				printMenuAfterDead();
				menuScreen(1);
			}
			if (newGAME.getPeople().isFinish())
			{
				newGAME.levelUp();
				count = 0;
			}
		}
		Sleep(10);
	}
}

void menuScreen(int option)
{
	while (option != 52)
	{
		switch (option)
		{
		case 49:
		{
			gotoXY(60, 3);
			IS_RUNNING = true;
			system("cls");
			newGAME.startGame();
			thread t1(ThreadFunc1);
			fixConsoleWindow();
			while (1)
			{
					int temp = toupper(_getch());
					KEY = temp;
					switch (KEY)
					{
					case 27: {
						newGAME.pauseGame();
						break;
					}
					case 52:
					{
						exitGame(&t1);
						return;
					}
					case 49:
					{
						if (IS_LOSE)
						{
							newGAME.resetGame();
							IS_RUNNING = true;
							menuScreen(49);
							break;
						}
						else
						{
							t1.join();
							menuScreen(KEY);
							break;
						}
					}
					case 50:
					{
						if (IS_LOSE)
						{
							cout << "Load Game";
							break;
						}
					}
					case 51:
					{
						menuScreen(52);
						break;
					}
					default:
					{
						break;
					}
					}
			}
			break;
		}
		case 50:
		{
			cout << "Pending";
			break;
		}
		case 51:
		{
			cout << "Pending";
			break;
		}
		default:
		{
			option = _getch();
			break;
		}
		}
	}
}



void main() {
	int option;
	PrintMenu();
	option = _getch();
	menuScreen(option);
}