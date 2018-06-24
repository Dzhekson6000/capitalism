#include "LoaderMap.h"
#include "Controller/Map/FactoryCells.h"
#include "tinyxml2/tinyxml2.h"
#include "tools/IsoTools.h"

using namespace tinyxml2;

LoaderMap::LoaderMap(LayerManager* layerManager, MapCity* map):
		layerManager(layerManager),
		map(map)
{}

LoaderMap::~LoaderMap()
{}

bool LoaderMap::load(const std::string &path)
{
	Image* imgmap = new Image();
	imgmap->initWithImageFile(path);
	loadMap(imgmap);
	
	return Loader::load(path);
}

void LoaderMap::loadMap(cocos2d::Image* mapImage)
{
	map->setSize(Size(mapImage->getWidth(), mapImage->getHeight()));
	
	Size size = Size(//Note:нужен размер в координатах, а не в клетках
			IsoTools::getNumberOfCell(mapImage->getWidth()),
			IsoTools::getNumberOfCell(mapImage->getHeight())
	);
	
	layerManager->setSizeGroup(size);
	
	if( mapImage->hasAlpha())
	{
		map->setCountChenal(4);
	}
	else
	{
		map->setCountChenal(3);
	}
	
	map->setLandscape(mapImage);
	
	for( int x = 0; x < map->getSize().width; ++x )
	{
		for( int y = 0; y < map->getSize().height; ++y )
		{
			IsoPoint point(x, y);
			Cell* cell = FactoryCells::getInstance()->createCell(map, point, map->getType(x, y));
			if( cell )
			{
				layerManager->addMapObject(cell);
			}
			else
			{
				CCLOG("Unable to render tile to position (%d,%d)", x, y);
			}
		}
	}
	
}
