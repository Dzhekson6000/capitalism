#include "BuildingAManager.h"

BuildingAgent* BuildingAManager::createBuildingAgent(Building* building)
{
	return new BuildingAgent(building);
}

BuildingAgent* BuildingAManager::getBuildingAgent(int id)
{
	for( auto agent: agents )
	{
		if(((BuildingAgent*)agent)->getBuilding()->getId() == id )
		{
			return dynamic_cast<BuildingAgent*>(agent);
		}
	}
	return nullptr;
}
