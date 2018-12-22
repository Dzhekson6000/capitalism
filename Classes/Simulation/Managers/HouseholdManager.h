#ifndef CAPITALISM_HOUSEHOLDMANAGER_H
#define CAPITALISM_HOUSEHOLDMANAGER_H

#include "AgentsManager.h"
#include "Simulation/Agents/Household.h"

class HouseholdManager: public AgentsManager
{
public:
	void addCluster(Household::Cluster* cluster);
};


#endif //CAPITALISM_HOUSEHOLDMANAGER_H
