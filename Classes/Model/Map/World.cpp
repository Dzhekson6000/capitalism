#include "World.h"
#include "Controller/BuildingController.h"
World::World():_map(nullptr)
{
}

World::~World()
{
}

bool World::init()
{
	if( !Scroller::init())
	{
		return false;
	}
	
	BuildingController::getInstance()->setWorld(this);
	
	_landscape = Layer::create();
	addChild(_landscape);
	
	_objects = Layer::create();
	addChild(_objects);
	
	return true;
}

void World::addLandscapeTile(Cell* cell)
{
	_landscape->addChild(cell);
}

void World::addObject(MapObject* object)
{
	_objects->addChild(object);
}

void World::removeObject(MapObject* object)
{
	_objects->removeChild(object);
}
