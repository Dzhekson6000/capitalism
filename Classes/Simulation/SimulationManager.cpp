#include "SimulationManager.h"

SimulationManager::SimulationManager():
	timer(0)
{
	companiesManager.setSimulationManager(this);
	buildingAManager.setSimulationManager(this);
	householdManager.setSimulationManager(this);
	
	market.setSimulationManager(this);
}

CompaniesManager* SimulationManager::getCompaniesManager()
{
	return &companiesManager;
}

BuildingAManager* SimulationManager::getBuildingAManager()
{
	return &buildingAManager;
}

HouseholdManager* SimulationManager::getHouseholdManager()
{
	return &householdManager;
}

void SimulationManager::update(float dt)
{
	timer+=dt;
	while(timer>1)
	{
		CCLOG("------------------------------------------------");
		CCLOG("ЗП рынка:%f, Еда по рынку:%f",market.getPrice(2),market.getPrice(4));
		companiesManager.update(dt);
		buildingAManager.update(dt);
		householdManager.update(dt);
		market.update(dt);
		timer-=1;
	}
}

Market* SimulationManager::getMarket()
{
	return &market;
}
