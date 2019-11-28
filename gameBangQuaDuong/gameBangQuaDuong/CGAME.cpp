#include "CGAME.h"

CGAME::CGAME() {
	CVEHICLE* temp1,* temp2,* temp3,* temp4, * temp5, * temp6, * temp7, * temp8, * temp9;
	
	temp1 = new CTRUCK;
	temp2 = new CTRUCK(10, 22, "Left");
	temp3 = new CTRUCK(19, 5, "Left");
	temp4 = new CTRUCK(50, 6, "Left");
	temp5 = new CTRUCK(67, 23, "Left");
	temp6 = new CTRUCK(13, 15, "Left");
	temp7 = new CTRUCK(12, 23, "Left");
	temp8 = new CTRUCK(20, 16, "Left");
	temp9 = new CTRUCK(18, 13, "Left");
	

	vehicles.push_back(temp1);
	vehicles.push_back(temp2);
	vehicles.push_back(temp3);
	vehicles.push_back(temp4);
	vehicles.push_back(temp5);
	vehicles.push_back(temp6);
	vehicles.push_back(temp7);
	vehicles.push_back(temp8);
	vehicles.push_back(temp9);

}

void CGAME::updatePosPeople(int mov) {
	switch (mov)
	{
	    case 80: {
	    	cn.Down(1);
	    	break;
	    }
	    case 72: {
	    	cn.Up(1);
	    	break;
	    }
	    case 75: {
	    	cn.Left(1);
	    	break;
	    }
	    case 77: {
	    	cn.Right(1);
	    	break;
	    }
		default: {
			break;
		}
    }
}

CGAME::~CGAME() {
	//...
}

void CGAME::startGame() 
{
	//..
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

vector<CVEHICLE *> CGAME::getVehicle() {
	return vehicles;
}

vector<CANIMAL*> CGAME::getAnimal() {
	return animals;
}