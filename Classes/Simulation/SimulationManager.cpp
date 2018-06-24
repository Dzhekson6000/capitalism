#include "SimulationManager.h"

SimulationManager::SimulationManager()
{}

CompaniesManager* SimulationManager::getCompaniesManager() const
{
	return &companiesManager;
}
