#pragma once
#include <iostream>
using namespace std;

class baseState
{

public:
	virtual string getName() = 0;
	virtual baseState* getnext() = 0;
};



class Morning : public baseState
{
public:
	string getName();
	baseState* getnext();
};
class Evening : public baseState
{
public:
	string getName();
	baseState* getnext();
};
class Night : public baseState
{
public:
	string getName();
	baseState* getnext();
};

class Sun
{
public:
	Sun();
	Sun(baseState* pContext);
	~Sun();
	void statechange();
	void getNameState(baseState* a);
protected:
	//void cleanUp();
	baseState* pState;
};
