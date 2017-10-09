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

void IsoPoint::updateIsometric()
{
	x = _xOriginal-_yOriginal;
	y = (_xOriginal+_yOriginal)/2;
}

int IsoPoint::getXCell()
{
	return floor(_xOriginal/23);
}

int IsoPoint::getYCell()
{
	return floor(_yOriginal/23);
}

void IsoPoint::setXCell(int x)
{
	_xOriginal = x*23;
	updateIsometric();
}

void IsoPoint::setYCell(int y)
{
	_yOriginal = y*23;
	updateIsometric();
}