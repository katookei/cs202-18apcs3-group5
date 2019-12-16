#pragma once
class CVEHICLE {
protected:
	int mX, mY;
public:
	virtual void Move() = 0;
	virtual void getStatus() = 0;
	int getMX();
	int getMY();
	//...
};