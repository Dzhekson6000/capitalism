#include "FactoryCells.h"
#include "Model/Map/Cell/RoadCell.h"
#include "Model/Map/Cell/RailRoadCell.h"
#include "Model/Map/Cell/ParkCell.h"
#include "Model/Map/Cell/TypesCell.h"

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
	ret->setType(MapObject::Type::LANDSCAPE);
	
	if(TypesCell::getNameCellOfType(type) == "tree")
	{
		ret->setTypeCell(0);
		ret->initObject();
		//addTreeCell(ret);
	}
	else
	{
		ret->setTypeCell(type);
		ret->initObject();
	}
	
	return ret;
}

void FactoryCells::addTreeCell(Cell* cell)
{
	/* TODO: нужно переделать и вынести добавление деревьев в Cell. Что бы было типо cell.tree = true*/
	/*SpriteFrame* sf = TileImageManager::getInstance()->getFrame("tiles", "tree");
	if( !sf )
	{
		return;
	}
	
	cocos2d::Sprite* s = Sprite::createWithSpriteFrame(sf);
	s->setPositionNormalized(cell->getAnchorPoint());
	cell->addChild(s);*/
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
