#include "Cell.h"
#include "TypesCell.h"

Cell::Cell()
{
}

bool Cell::initObject()
{
	groupSprite = "tiles";
	nameSprite = TypesCell::getNameCellOfType(_type);
	frame = 1;
	
	//printDebugCell(std::to_string((int)_isoPoint.getCell().x)+":"+std::to_string((int)_isoPoint.getCell().y));
	
	return MapObject::initObject();
}

int Cell::getBitMask()
{
	int ret = 0;
	
	if( checkSameType(-1, 0))
	{
		ret += 1;
	}
	if( checkSameType(1, 0))
	{
		ret += 2;
	}
	if( checkSameType(0, -1))
	{
		ret += 4;
	}
	if( checkSameType(0, 1))
	{
		ret += 8;
	}
	
	return ret;
}

int Cell::getTypeOffset(int x, int y)
{
	Point p = isoPoint.getCell();
	return _map->getType(p.x+x, p.y+y);
}

bool Cell::checkSameType(int x, int y)
{
	return getTypeOffset(x, y) == _type;
}
