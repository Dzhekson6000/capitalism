#include "AgentsManager.h"

void AgentsManager::addNew(Agent* agent)
{
	agent->setSimulationManager(simulationManager);
	if(agent->init())
	{
		agents.push_back(agent);
	}
	else
	{
		delete agent;
	}
}

const std::vector<Agent*> &AgentsManager::getAgents() const
{
	return agents;
}

void AgentsManager::update(float dt)
{
	for( auto agent: agents)
	{
		agent->update(dt);
	}
}

Manager* AgentsManager::getSimulationManager() const
{
	return simulationManager;
}

void AgentsManager::setSimulationManager(Manager* simulationManager)
{
	AgentsManager::simulationManager = simulationManager;
}
