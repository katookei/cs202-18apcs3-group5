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
			newGAME.updatePosAnimal();
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

void ThreadFunc2()
{
	while (IS_RUNNING)
	{
		for (int i = 0; i < newGAME.getAnimal().size(); i++)
		{

			newGAME.getAnimal()[i]->updateStatus();
			Sleep(2000);
		}
		/*for (int i = 0; i < newGAME.getVehicle().size(); i++)
		{
			newGAME.getVehicle()[i]->getStatus(yes);
			Sleep(2000);
			newGAME.getVehicle()[i]->getStatus(no);
		}*/
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
			thread t2(ThreadFunc2);
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