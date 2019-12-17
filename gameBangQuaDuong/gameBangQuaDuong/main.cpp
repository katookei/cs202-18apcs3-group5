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
	int count = 0;
	newGAME.setlight();
	while (IS_RUNNING) {
		if (!newGAME.getIsPaused()) {
			gotoXY(2, 3);
			cout << "level " << newGAME.lvl;
			gotoXY(RIGHT - 20, 3);
			cout << "Press <ESC> to pause game";
			if (KEY != NULL) {
				newGAME.updatePosPeople(KEY);
				KEY = NULL;
			}
			newGAME.updatePosVehicle();
			newGAME.updatePosAnimal();
			
			
			if (count == 50)
			{
				newGAME.getlight()[2].changecolor();
				newGAME.getlight()[3].changecolor();
				newGAME.getlight()[0].changecolor();
				 for(int i = 0;i < newGAME.getlight().size();i++)
				{
				newGAME.getlight()[i].draw();// xanh 10 do 12
				}
				 for (int i = 0;i < newGAME.getVehicle().size();i++)
				 {
					 if (newGAME.getVehicle()[i]->getType() == newGAME.getlight()[0].getobject())
					 {
						 newGAME.getVehicle()[i]->updateStatus();
						 break;
					 }
				 } 
				
			}

			if (count == 0)
			{
				newGAME.getlight()[1].changecolor();
				/*newGAME.getlight()[0].changecolor();*/
				newGAME.getlight()[2].changecolor();
				newGAME.getlight()[3].changecolor();
				for (int i = 0;i < newGAME.getlight().size();i++)
				{
					newGAME.getlight()[i].draw();
				}
				for (int i = 0;i < newGAME.getVehicle().size();i++)
				{
					if (newGAME.getVehicle()[i]->getType() == newGAME.getlight()[1].getobject())
					{
						newGAME.getVehicle()[i]->updateStatus();
						break;
					}
					/*if(newGAME.getVehicle()[i]->getType() == newGAME.getlight()[0].getobject())
					{
						newGAME.getVehicle()[i]->updateStatus();
					}*/
				}
				
				count = 100;
			}
			--count;
			/*for (int i = 0; i < newGAME.getVehicle().size(); i++)
			{
				if (type != newGAME.getVehicle()[i]->getType()) {
					type = newGAME.getVehicle()[i]->getType();
					cout << type;
					newGAME.getVehicle()[i]->updateStatus();
				}
			}*/
			if (newGAME.getPeople().isImpact(newGAME.getVehicle()) ||
				newGAME.getPeople().isImpact(newGAME.getAnimal())) {
				IS_LOSE = true;
				newGAME.getPeople().isDead();
                printMenuAfterDead();
				menuScreen(1);
				count = 0;
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
		int flag = true;
		switch (option)
		{
		case 49:
		{
			gotoXY(60, 3);
			IS_RUNNING = true;
			system("cls");
			newGAME.drawGame();
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
						exitGame(&t1);
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
			newGAME.loadGame();
			gotoXY(60, 3);
			IS_RUNNING = true;
			system("cls");
			newGAME.drawGame();
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
		case 51:
		{
			//newGAME.exitGame();
			flag = false;
			break;
		}
		default:
		{
			option = _getch();
			break;
		}
		}
		if (!flag) break;
	}
}



void main() {
	int option;
	PrintMenu();
	option = _getch();
	menuScreen(option);
}