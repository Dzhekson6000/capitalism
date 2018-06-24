#include "IsoPoint.h"
#include "tools/IsoTools.h"
#include "Model/Config.h"

IsoPoint::IsoPoint()
{
}

IsoPoint::IsoPoint(cocos2d::Point point)
{
	initOfScreen(point.x, point.y);
}

IsoPoint::IsoPoint(int x, int y):
		IsoPoint(
				(float)IsoTools::getNumberOfCell(x),
				(float)IsoTools::getNumberOfCell(y)
		)
{
}

IsoPoint::IsoPoint(float x, float y)
{
	initOfIso(x, y);
}

void IsoPoint::initOfIso(const cocos2d::Point point)
{
	initOfIso(point.x, point.y);
}

void IsoPoint::initOfScreen(const cocos2d::Point point)
{
	initOfScreen(point.x,point.y);
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

void IsoPoint::updateScreen()
{
	IsoTools::isoToScreen(_isoPoint.x, _isoPoint.y, this->x, this->y);
}

void IsoPoint::updateIso()
{
	IsoTools::screenToIso(this->x, this->y, _isoPoint.x, _isoPoint.y);
}

void IsoPoint::reductionToCell()
{
	initOfIso(
			IsoTools::getCellOfNumber(_isoPoint.x)*Config::TILE_SIZE,
			IsoTools::getCellOfNumber(_isoPoint.y)*Config::TILE_SIZE
	);
}

cocos2d::Point IsoPoint::getCell() const
{
	return cocos2d::Point(
			IsoTools::getCellOfNumber(_isoPoint.x),
			IsoTools::getCellOfNumber(_isoPoint.y)
	);
}