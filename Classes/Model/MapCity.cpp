#include "MapCity.h"
#include "IsoPoint.h"
#include "Tools/FactoryCells.h"

USING_NS_CC;

MapCity::MapCity():
		_widthMap(300),
		_heightMap(300),
		_map(nullptr)
{
}

MapCity::~MapCity()
{
	releaseMap();
}

void MapCity::releaseMap()
{
	if( _map )
	{
		delete _map;
		_map = nullptr;
	}
}

void MapCity::loadMap(cocos2d::Image* map)
{
	releaseMap();
	_widthMap  = map->getWidth();
	_heightMap = map->getHeight();
	
	_countChenal = 3;
	if( map->hasAlpha())
	{
		_countChenal = 4;
	}
	
	_map = map;
	
}

void MapCity::draw(cocos2d::Node* scene)
{
	for( int x = _widthMap-1; x >= 0; x-- )
	{
		for( int y = _heightMap-1; y >= 0; y-- )
		{
			IsoPoint point(x, y);
			Cell* cell = FactoryCells::getInstance()->createCell(this, point, getType(x, y));
			if( cell )
			{
				scene->addChild(cell);
			}
			else
			{
				CCLOG("Unable to render tile to position (%d,%d)",x,y);
			}
		}
	}
}

unsigned char* MapCity::getPixel(int x, int y)
{
	return _map->getData() + (x + y*_widthMap)*_countChenal;
}

int MapCity::getType(int x, int y)
{
	int type = *(getPixel(x, y)+2);
	if(type==132) type = 4;//TODO: временный хак что бы не рисовать парковки
	return type;
}
