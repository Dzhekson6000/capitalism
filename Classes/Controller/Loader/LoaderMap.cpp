#include "LoaderMap.h"
#include "Controller/FactoryCells.h"
#include "tinyxml2/tinyxml2.h"

using namespace tinyxml2;

LoaderMap::LoaderMap(World* world):
		_world(world)
{
}

LoaderMap::~LoaderMap()
{
}

void LoaderMap::loadMap(cocos2d::Image* mapImage)
{
	MapCity* map = _world->getMap();
	if(!map)
	{
		map=new MapCity();
		_world->setMap(map);
	}
	map->release();
	map->setWidth(mapImage->getWidth());
	map->setHeight(mapImage->getHeight());
	if( mapImage->hasAlpha())
	{
		map->setCountChenal(4);
	}
	else
	{
		map->setCountChenal(3);
	}
	
	map->setLandscape(mapImage);
}

void LoaderMap::loadMap(std::string mapPath)
{
	Image* imgmap = new Image();
	imgmap->initWithImageFile(mapPath);
	loadMap(imgmap);
}

void LoaderMap::draw()
{
	MapCity* map = _world->getMap();
	for( int x = 50/*map->getWidth()*/-1; x >= 0; x-- )
	{
		for( int y = 50/*map->getHeight()*/-1; y >= 0; y-- )
		{
			IsoPoint point(x, y);
			Cell* cell = FactoryCells::getInstance()->createCell(map, point, map->getType(x, y));
			if( cell )
			{
				_world->addLandscapeTile(cell);
			}
			else
			{
				CCLOG("Unable to render tile to position (%d,%d)",x,y);
			}
		}
	}
	
	for(auto o: map->getMapObject())
	{
		_world->addChild(o);
	}
}
