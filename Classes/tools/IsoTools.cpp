#include "IsoTools.h"

void IsoTools::isoToScreen(const float isoX, const float isoY, float &x, float &y)
{
	x = isoX - isoY;
	y = (isoX + isoY)/2;
}

void IsoTools::screenToIso(const float x, const float y, float &isoX, float &isoY)
{
	isoX = y + x/2;
	isoY = y - x/2;
}

