#include "IsoPoint.h"
#include "tools/IsoTools.h"
#include "Config.h"

IsoPoint::IsoPoint()
{
}

IsoPoint::IsoPoint(cocos2d::Point point)
{
	initOfScreen(point.x, point.y);
}

IsoPoint::IsoPoint(int x, int y):IsoPoint((float)x*Config::TILE_SIZE, (float)y*Config::TILE_SIZE)
{
}

IsoPoint::IsoPoint(float x, float y)
{
	initOfIso(x, y);
}

void IsoPoint::initOfIso(const float x, const float y)
{
	this->_isoPoint = cocos2d::Point(x, y);
	IsoTools::isoToScreen(x, y, this->x, this->y);
}

void IsoPoint::initOfScreen(const float x, const float y)
{
	this->x = x;
	this->y = y;
	IsoTools::screenToIso(x, y, _isoPoint.x, _isoPoint.y);
}

void IsoPoint::reductionToCell()
{
	initOfIso(floor(_isoPoint.x/Config::TILE_SIZE + 0.5f)*Config::TILE_SIZE, floor(_isoPoint.y/Config::TILE_SIZE + 0.5f)*Config::TILE_SIZE);
}

cocos2d::Point IsoPoint::getCell() const
{
	return cocos2d::Point(floor(_isoPoint.x/Config::TILE_SIZE + 0.5f), floor(_isoPoint.y/Config::TILE_SIZE + 0.5f));
}