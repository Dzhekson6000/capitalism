#ifndef CAPITALISM_ISOPOINT_H
#define CAPITALISM_ISOPOINT_H

#include "cocos2d.h"

class IsoPoint: public cocos2d::Point
{
public:
	IsoPoint();
	IsoPoint(cocos2d::Point point);
	IsoPoint(int x, int y);
	IsoPoint(float x, float y);
	
	cocos2d::Point getCell();
	
	void isoToScreen(float x, float y);
	void screenToIso(float x, float y);
	
	CC_SYNTHESIZE_READONLY(cocos2d::Point, _isoPoint, Original);
};


#endif //CAPITALISM_ISOPOINT_H
