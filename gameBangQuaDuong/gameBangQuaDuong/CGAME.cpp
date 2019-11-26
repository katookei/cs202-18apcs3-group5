#include "CGAME.h"

CGAME::CGAME() {
	//...
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