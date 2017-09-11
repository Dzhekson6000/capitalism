#ifndef CAPITALISM_ISOPOINT_H
#define CAPITALISM_ISOPOINT_H

#include "cocos2d.h"

class IsoPoint
{
private:
	//isometric coordinates
	float _x;
	float _y;
	//real coordinates
	float _xOriginal;
	float _yOriginal;
	void updateIsometric();

public:
	IsoPoint(){};
	IsoPoint(float x, float y);
	IsoPoint(int x, int y);
	float getX(){return _x; };
	float getY(){return _y; };
	float getXOriginal(){return _xOriginal; };
	float getYOriginal(){return _yOriginal; };
	int getXCell();
	int getYCell();
	void setXCell(int x);
	void setYCell(int y);
	void setPoint(float x, float y);
};


#endif //CAPITALISM_ISOPOINT_H
