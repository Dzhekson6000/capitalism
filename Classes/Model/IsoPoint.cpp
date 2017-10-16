#include "IsoPoint.h"

IsoPoint::IsoPoint()
{}

IsoPoint::IsoPoint(cocos2d::Point point):IsoPoint(point.x,point.y)
{}

IsoPoint::IsoPoint( int x, int y ):IsoPoint((float)x*23,(float)y*23)
{
}

IsoPoint::IsoPoint(float x, float y)
{
	isoToScreen(x,y);
}

void IsoPoint::isoToScreen(float x, float y)
{
	_isoPoint.x = x;
	_isoPoint.y = y;
	this->x = x-y;
	this->y = (x+y)/2;
}

void IsoPoint::screenToIso(float x, float y)
{
	this->x = x;
	this->y = y;
	_isoPoint.x = y + x / 2;
	_isoPoint.y = y - x / 2;
	
}

void IsoPoint::reductionToCell()
{
	isoToScreen(floor(_isoPoint.x/23+0.5f)*23, floor(_isoPoint.y/23+0.5f)*23);
}

cocos2d::Point IsoPoint::getCell() const
{
	return cocos2d::Point(floor(_isoPoint.x/23+0.5f),floor(_isoPoint.y/23+0.5f));
}