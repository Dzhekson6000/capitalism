#include "World.h"
#include "Controller/BuildingController.h"
#include "Controller/Loader/LoaderMap.h"
#include "Controller/Loader/LoaderMapObject.h"

World::World():_map(nullptr)
{
}

World::~World()
{
	if(_map)
	{
		delete _map;
	}
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

void World::loadMap(std::string mapPath)
{
	LoaderMap loaderMap(this);
	loaderMap.loadMap(mapPath);
}

void World::loadMapObject(std::string path)
{
	//LoaderMapObject loaderMapObject(this);
	//loaderMapObject.loadMapObjectFile(path);
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
