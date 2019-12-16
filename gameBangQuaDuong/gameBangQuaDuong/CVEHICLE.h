#pragma once
class CVEHICLE {
protected:
	int mX, mY;
public:
	virtual void Move() = 0;
	int getMX();
	int getMY();
	virtual int getType() = 0;
	virtual void updateStatus()=0;
	virtual bool isTouched(int x, int y) = 0;
	//...
};