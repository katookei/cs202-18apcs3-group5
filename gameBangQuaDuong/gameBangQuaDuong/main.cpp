#include"CGAME.h"
using namespace std;

bool IS_RUNNING = true;
int KEY = NULL;
CGAME newGAME;

void exitGame(thread *t1) {
	system("cls");
	IS_RUNNING = false;
	t1->join();
}

void ThreadFunc1() {
	while (IS_RUNNING) {
		if (!newGAME.getIsPaused()) {
			if (KEY != NULL) {
				newGAME.updatePosPeople(KEY);
				KEY = NULL;
			}
			newGAME.updatePosVehicle();
			if (newGAME.getPeople().isImpact(newGAME.getVehicle()) ||
				newGAME.getPeople().isImpact(newGAME.getAnimal())) {
				IS_RUNNING = false;
                system("cls");
			    PrintMenu();
			}
		}
		Sleep(25);
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
					t1.join();
					menuScreen(KEY);
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