#include "AgentsManager.h"

void AgentsManager::addNew(Agent* agent)
{
	agents.push_back(agent);
}

const std::vector<Agent*> &AgentsManager::getAgents() const
{
	return agents;
}

void AgentsManager::update(float dt)
{
}
