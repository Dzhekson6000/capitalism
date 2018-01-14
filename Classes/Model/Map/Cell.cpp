#include "Cell.h"
#include "Controller/TileImageManager.h"

//TODO:: нужно перенести это в конфиг файл и загружать все именна из конфига
const std::unordered_map<int, std::string> Cell::_cellsName
		                                     {
				                                     { 0,"ground"},
				                                     { 1,"tundra"},
				                                     { 2,"dryground"},
				                                     { 4, "road"},
				                                     { 8,"railroad"},
				                                     { 12,"crossage"},
				                                     { 128,"grass"},
				                                     { 129,"desert"},
				                                     { 130,"plage"},
				                                     { 131,"city"},
				                                     { 132,"court"},
				                                     { 133,"park"},
				                                     { 134,"asphault"},
				                                     { 135,"square"},
				                                     { 136,"industrial"},
				                                     { 255,"water"},
				                                     { 36,"tree"}
		                                     };

Cell::Cell()
{
}

bool Cell::initTile()
{
	std::string name = "tiles/";
	name+=getNameCellOfType(_type);
	name+="/1.png";
	
	return Sprite::initWithSpriteFrameName(name);
}

int Cell::getFrame()
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
	Point p = _isoPoint.getCell();
	return _map->getType(p.x+x, p.y+y);
}

bool Cell::checkSameType(int x, int y)
{
	return getTypeOffset(x, y) == _type;
}

void Cell::setIsoPoint(const IsoPoint isoPoint)
{
	_isoPoint = isoPoint;
	setPosition(_isoPoint);
}

std::string Cell::getNameCellOfPixel(const unsigned char* pixel)
{
	return getNameCellOfType(*(pixel + 2));
}

std::string Cell::getNameCellOfType(const int type)
{
	auto name = _cellsName.find(type);
	if(name == _cellsName.end())
	{
		CCLOG("Cell name id %d not found", type);
		return "";
	}
	return name->second;
}

void Cell::printDebugCell(std::string text)
{
	auto label = Label::createWithTTF(text.c_str(), "fonts/arial.ttf", 14);
	label->setTextColor(Color4B::RED);
	label->setPositionNormalized(getAnchorPoint());
	addChild(label, 2);
}
