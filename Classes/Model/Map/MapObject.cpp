#include "MapObject.h"
#include "Controller/TileImageManager.h"

MapObject::MapObject()
{
	
}

bool MapObject::initObject()
{
	SpriteFrame* sf = TileImageManager::getInstance()->getFrame(_group, _name, 1);
	if( !sf )
	{
		return false;
	}
	
	return Sprite::initWithSpriteFrame(sf);
}

void MapObject::setIsoPoint(const IsoPoint isoPoint)
{
	_isoPoint = isoPoint;
	setLocalZOrder(10000-(isoPoint.getCell().x + isoPoint.getCell().y));//TODO: временный хак что бы правильно рисовать по Z. могут быть косяки при большой карте
	setPosition(_isoPoint);
}
