#pragma once
class CANIMAL {
protected:
	int mX, mY;
public:
	virtual void Move(int, int)=0;
	virtual void Tell()=0;
	int getMX();
	int getMY();
};
