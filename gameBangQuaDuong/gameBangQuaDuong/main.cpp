#include"CGAME.h"
using namespace std;

bool IS_RUNNING = true;
int KEY = NULL;
CGAME newGAME;

void exitGame(thread* t) {
	system("cls");
	IS_RUNNING = false;
	t->join();
}

void ThreadFunc1() {
	gotoXY(90, 1);
	while (IS_RUNNING) {
		if (KEY != NULL) {
			newGAME.updatePosPeople(KEY);
			KEY = NULL;
		} 
		
		newGAME.updatePosVehicle();
		if (newGAME.getPeople().isImpact(newGAME.getVehicle()) ||
			newGAME.getPeople().isImpact(newGAME.getAnimal())) {
			IS_RUNNING = false;
		}
		Sleep(25);
	}
}

void main() {
	newGAME.startGame();
    thread t1(ThreadFunc1);
	fixConsoleWindow();
	while (1)
	{
		int temp = toupper(_getch());
		KEY = temp;
		switch (temp) {
		    case 27: {
		    	exitGame(&t1);
		    	return;
		    }
		   //..
		}

	}
				
}