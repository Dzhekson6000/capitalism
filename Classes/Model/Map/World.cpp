#include "World.h"

World::World():
_map(nullptr)
{
}

bool World::init()
{
	if(!Scroller::init())
	{
		return false;
	}
	
	_landscape=Layer::create();
	addChild(_landscape);
	
	return true;
}

void World::addLandscapeTile(Cell* cell)
{
	_landscape->addChild(cell);
}
