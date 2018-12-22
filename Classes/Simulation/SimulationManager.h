#ifndef CAPITALISM_SIMULATIONMANAGER_H
#define CAPITALISM_SIMULATIONMANAGER_H

#include "Base/Manager.h"
#include "Managers/CompaniesManager.h"
#include "Managers/BuildingAManager.h"
#include "Managers/HouseholdManager.h"
#include "Agents/Market/Market.h"

class SimulationManager:public Manager
{
public:
	SimulationManager();
	
	CompaniesManager* getCompaniesManager();
	BuildingAManager* getBuildingAManager();
	HouseholdManager* getHouseholdManager();
	
	Market* getMarket();
	
	void update(float dt);

private:
	CompaniesManager companiesManager;
	BuildingAManager buildingAManager;
	HouseholdManager householdManager;
	Market market;
	
	float timer;
	
};


#endif //CAPITALISM_SIMULATIONMANAGER_H
