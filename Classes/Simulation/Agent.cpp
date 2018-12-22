#include "Agent.h"

Agent::Agent()
{
}

bool Agent::init()
{
	return true;
}

bool Agent::message(Message& message)
{
	return true;
}

void Agent::update(float dt)
{}

Manager* Agent::getSimulationManager() const
{
	return simulationManager;
}

void Agent::setSimulationManager(Manager* simulationManager)
{
	Agent::simulationManager = simulationManager;
}

const std::unordered_map<int, float> &Agent::getOwns() const
{
	return owns;
}

float Agent::getOwn(int id) const
{
	auto own = owns.find(id);
	if(own != owns.end())
	{
		return own->second;
	}
	return 0;
}

void Agent::setOwn(int id, float volume)
{
	auto p = owns.insert({id, volume});
	if (!p.second) {
		p.first->second = volume;
	}
}


