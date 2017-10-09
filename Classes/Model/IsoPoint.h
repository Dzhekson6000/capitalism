#ifndef CAPITALISM_ISOPOINT_H
#define CAPITALISM_ISOPOINT_H

#include "cocos2d.h"

class IsoPoint: public cocos2d::Point
{
private:
	void updateIsometric();
public:
	//real coordinates
	CC_SYNTHESIZE_READONLY(float, _xOriginal, XOriginal);
	CC_SYNTHESIZE_READONLY(float, _yOriginal, YOriginal);
	
	IsoPoint(){};
	IsoPoint(float x, float y);
	IsoPoint(int x, int y);
	void setPoint(float x, float y);
	
	int getXCell();
	int getYCell();
	void setXCell(int x);
	void setYCell(int y);
};


#endif //CAPITALISM_ISOPOINT_H
