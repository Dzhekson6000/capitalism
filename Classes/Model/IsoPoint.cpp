#include "IsoPoint.h"

IsoPoint::IsoPoint(float x, float y)
{
	setPoint(x,y);
}

IsoPoint::IsoPoint( int x, int y )
{
	setPoint(x*23,y*23);
}

void IsoPoint::setPoint(float x, float y)
{
	_xOriginal = x;
	_yOriginal = y;
	updateIsometric();
}

int IsoPoint::getXCell()
{
	return floor(_xOriginal/50);
}

int IsoPoint::getYCell()
{
	return floor(_yOriginal/50);
}

void IsoPoint::setXCell(int x)
{
	_xOriginal = x*50;
	updateIsometric();
}

void IsoPoint::setYCell(int y)
{
	_yOriginal = y*50;
	updateIsometric();
}

void IsoPoint::updateIsometric()
{
	_x = _xOriginal-_yOriginal;
	_y = (_xOriginal+_yOriginal)/2;
}