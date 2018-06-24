#include "SimulationManager.h"

SimulationManager::SimulationManager()
{}

CompaniesManager* SimulationManager::getCompaniesManager()
{
	return &companiesManager;
}
