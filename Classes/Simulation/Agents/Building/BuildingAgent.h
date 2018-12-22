#ifndef CAPITALISM_BUILDINGAGENT_H
#define CAPITALISM_BUILDINGAGENT_H

#include "Simulation/Agent.h"
#include "Model/Map/Building/Building.h"
#include "Simulation/Agents/Household.h"

class BuildingAgent: public Agent
{
public:
	explicit BuildingAgent(Building* building);
	~BuildingAgent();
	
	bool init() override;
	void update(float dt) override;
	
	Building* getBuilding() const;
	Household::Cluster* getHouseholdCluster() const;
	
	float getSalary() const;
	void setSalary(float salary);

private:
	Building* building;
	Household::Cluster* householdCluster;
	
	float salary;
	float price;
	float sb;
	float timer;
	
	void hiring();///< получаем рабочую силу
	void fabrication();///< производим
	void sale();///< продаём
};


#endif //CAPITALISM_BUILDINGAGENT_H
