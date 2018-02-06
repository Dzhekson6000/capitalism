#include "World.h"
#include "Controller/BuildingController.h"
#include "Controller/Loader/LoaderMap.h"
#include "Controller/Loader/LoaderMapObject.h"
#include "tools/IsoTools.h"
#include "Model/Camera.h"

World::World():_map(nullptr)
{
}

World::~World()
{
	if( _map )
	{
		delete _map;
	}
}

bool World::init()
{
	if( !IsoScroller::init())
	{
		return false;
	}
	
	BuildingController::getInstance()->setWorld(this);
	
	_objects = GroupObject::create();
	addChild(_objects);
	
	return true;
}

void World::loadMap(std::string mapPath)
{
	LoaderMap loaderMap(this);
	loaderMap.loadMap(mapPath);
	
	_objects->updateInvisible(*this);
}

void World::loadMapObject(std::string path)
{
	//LoaderMapObject loaderMapObject(this);
	//loaderMapObject.loadMapObjectFile(path);
}

void World::updateIsoPoints()
{
	IsoScroller::updateIsoPoints();
	_objects->updateIsoPoints();
}

void World::addLandscapeTile(MapObject* cell)
{
	_objects->addObject(cell);
}

GroupObject* World::getObjects()
{
	return _objects;
}

void World::addObject(MapObject* object)
{
	//_objects->addChild(object);
}

void World::removeObject(MapObject* object)
{
	//_objects->removeChild(object);
}

void World::onMove()
{
	_objects->updateInvisible(*this);
}

void World::setScale(float scale)
{
	//пытаемся отцентровать
	float dScale = getScale()-scale;
	setPositionX(getPositionX() + getContentSize().width/2*dScale);
	setPositionY(getPositionY() + getContentSize().height/2*dScale);
	
	
	IsoScroller::setScale(scale);
	_objects->updateInvisible(*this);
}
