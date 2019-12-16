#pragma once
#include"Header.h"
#include"CVEHICLE.h"
#include"CANIMAL.h"
class CPEOPLE {
	int mX, mY;
	bool mState; //Trạng thái sống chết
public:
	CPEOPLE();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const vector<CVEHICLE*>&);
	bool isImpact(const vector<CANIMAL*>&);
	bool isFinish();
	bool isDead();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	void resetPoṣ̣();
};
