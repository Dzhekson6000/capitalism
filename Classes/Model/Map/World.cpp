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
	
	return true;
}

void World::addLandscapeTile(Cell* cell)
{
	_landscape->addChild(cell);
}