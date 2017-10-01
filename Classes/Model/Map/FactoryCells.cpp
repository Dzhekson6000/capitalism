#include "FactoryCells.h"
#include "Tools/ImageManager.h"
#include "Model/Map/Cells/RoadCell.h"
#include "Model/Map/Cells/RailRoadCell.h"
#include "Model/Map/Cells/ParkCell.h"

FactoryCells* FactoryCells::_factoryCells = nullptr;

FactoryCells* FactoryCells::getInstance()
{
	if(_factoryCells== nullptr)
	{
		_factoryCells = new FactoryCells();
	}
	return _factoryCells;
}

FactoryCells::FactoryCells()
{
}

FactoryCells::~FactoryCells()
{
}

Cell* FactoryCells::createCell(MapCity* map, IsoPoint point, int type)
{
	Cell* ret = createCellOfType(type);
	ret->setMap(map);
	ret->setIsoPoint(point);
	
	if(Cell::getNameCellOfType(type) == "tree")
	{
		ret->setType(0);
		ret->initTile();
		//addTreeCell(ret);
	}
	else
	{
		ret->setType(type);
		ret->initTile();
	}
	
	return ret;
}

void FactoryCells::addTreeCell(Cell* cell)
{
	SpriteFrame* sf = ImageManager::getInstance()->getFrame("tiles", "tree");
	if( !sf )
	{
		return;
	}
	
	cocos2d::Sprite* s = Sprite::createWithSpriteFrame(sf);
	s->setPositionNormalized(cell->getAnchorPoint());
	cell->addChild(s);
}

Cell* FactoryCells::createCellOfType(int type)
{
	switch(type)
	{
		case 4:
			return RoadCell::create();
		case 8:
			return RailRoadCell::create();
		case 133:
			return ParkCell::create();
		default:
			return Cell::create();
	}
}
