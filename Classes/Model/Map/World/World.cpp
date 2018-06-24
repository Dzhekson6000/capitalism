#include "World.h"
#include "Loader/Map/LoaderMap.h"
#include "Loader/Map/LoaderCompany.h"
#include "Loader/Map/LoaderMapObject.h"
#include "Simulation/SimulationManager.h"

World::World():_map(nullptr)
{
}

bool World::init()
{
	if( !IsoScroller::init())
	{
		return false;
	}
	
	_map = new MapCity();
	
	layerManager = new LayerManager(this);
	simulationManager = new SimulationManager();
	buildingManager = new BuildingManager(layerManager,this);
	
	return true;
}

World::~World()
{
	if( _map )
	{
		delete _map;
	}
	
	delete layerManager;
	delete simulationManager;
	delete buildingManager;
}

bool World::load(const std::string &path)
{
	LoaderMap loaderMap(layerManager,_map);
	loaderMap.load(path+".png");
	
	std::string pathXml = path+".xml";
	
	LoaderCompany loaderCompany(simulationManager->getCompaniesManager());
	loaderCompany.load(pathXml);
	
	LoaderMapObject loaderMapObject(layerManager);
	loaderMapObject.load(pathXml);
	
	return Loader::load(path);
}

void World::updateIsoPoints()
{
	IsoScroller::updateIsoPoints();
	layerManager->updateIsoPoints();
}

void World::onMove()
{
	layerManager->updateInvisible();
}

void World::onClickCell(const IsoPoint &point)
{
	if( buildingManager->getBuildingMode())
	{
		buildingManager->onClick();
	}
	
	IsoScroller::onClickCell(point);
}


BuildingManager* World::getBuildingManager() const
{
	return buildingManager;
}

void World::update(float dt)
{
	Node::update(dt);
}
