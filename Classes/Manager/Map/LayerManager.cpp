#include "LayerManager.h"

LayerManager::LayerManager(Layer* world):layer(world)
{
	tiles = GroupObject::create();
	world->addChild(tiles, 1);
	
	objects = GroupObject::create();
	world->addChild(objects, 2);
}

void LayerManager::addMapObject(MapObject* mapObject)
{
	switch( mapObject->getType())
	{
		case MapObject::Type::LANDSCAPE:
			tiles->addObject(mapObject);
			break;
		case MapObject::Type::BUILDING:
			objects->addObject(mapObject);
			break;
		default:
			break;
	}
}

void LayerManager::updateInvisible()
{
	tiles->updateInvisible(*((IsoScroller*)layer));
	objects->updateInvisible(*((IsoScroller*)layer));
}

void LayerManager::updateIsoPoints()
{
	tiles->updateIsoPoints();
	objects->updateIsoPoints();
}

void LayerManager::setSizeGroup(const cocos2d::Size &size)
{
	objects->setSizeGroup(size);
	tiles->setSizeGroup(size);
}
