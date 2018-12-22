#ifndef CAPITALISM_BUILDINGMANAGER_H
#define CAPITALISM_BUILDINGMANAGER_H

#include "AgentsManager.h"
#include "Model/Map/Building/Building.h"
#include "Simulation/Agents/Building/BuildingAgent.h"

class BuildingAManager: public AgentsManager
{
public:
	BuildingAgent* createBuildingAgent(Building* building);
	
	BuildingAgent* getBuildingAgent(int id);
};


#endif //CAPITALISM_BUILDINGMANAGER_H
