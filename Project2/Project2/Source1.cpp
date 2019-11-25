#include "Header.h"
#include <string>

baseState* Morning::getnext()
{
	return new Evening;
}

string Morning::getName()
{
	return "morning";
}

string Evening::getName()
{
	return "evening";
}

string Night::getName()
{
	return "night";
}


baseState* Evening::getnext()
{
	return new Night;
}
baseState* Night::getnext()
{
	return new Morning;
}

void Sun::statechange()
{
	if (pState)
	{
		baseState* State = pState->getnext();
		delete State;
		pState = State;
	}
}

Sun::Sun()
{
	pState = new Morning;
}
Sun::~Sun()
{
	delete[] pState;
}
Sun::Sun(baseState* pContext)
{
	pState = pContext;
}
void Sun::getNameState(baseState* a)
{
  cout << a->getName();
}