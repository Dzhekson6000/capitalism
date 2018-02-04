#include "IsoTools.h"
#include "Model/Camera.h"
#include "Model/Config.h"
#include <cmath>

void IsoTools::isoToScreen(const float isoX, const float isoY, float &x, float &y)
{
	switch(Camera::getInstance()->getDirection())
	{
		case Camera::Direction::NorthWest:
			x = isoY - isoX;
			y = (isoX + isoY);
			break;
		case Camera::Direction::EastNorth:
			x = -(isoX + isoY);
			y = (isoY - isoX);
			break;
		case Camera::Direction::SouthEast:
			x = isoX - isoY;
			y = -(isoX + isoY);
			break;
		case Camera::Direction::WestSouth:
			x = isoX + isoY;
			y = isoX - isoY;
			break;
	}
	y/=2;
}

void IsoTools::screenToIso(const float x, const float y, float &isoX, float &isoY)
{
	switch(Camera::getInstance()->getDirection())
	{
		case Camera::Direction::NorthWest:
			isoX = y - x/2;
			isoY = y + x/2;
			break;
		case Camera::Direction::EastNorth:
			isoX = -(y + x/2);
			isoY = y - x/2;
			break;
		case Camera::Direction::SouthEast:
			isoX = x/2 - y;
			isoY = -(x/2 + y);
			break;
		case Camera::Direction::WestSouth:
			isoX = x/2 + y;
			isoY = x/2 - y;
			break;
	}
}

int IsoTools::getCellOfNumber(const float size)
{
	return floor(size/Config::TILE_SIZE + 0.5f);
}

float IsoTools::getNumberOfCell(const int cell)
{
	return cell*Config::TILE_SIZE;
}
