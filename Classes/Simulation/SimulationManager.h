#ifndef CAPITALISM_SIMULATIONMANAGER_H
#define CAPITALISM_SIMULATIONMANAGER_H

#include "Base/Manager.h"
#include "Managers/CompaniesManager.h"

class SimulationManager: public Manager
{
public:
	SimulationManager();
	
	CompaniesManager* getCompaniesManager() const;

private:
	CompaniesManager companiesManager;
	
};


#endif //CAPITALISM_SIMULATIONMANAGER_H
