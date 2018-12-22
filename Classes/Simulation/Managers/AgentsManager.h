#ifndef CAPITALISM_AGENTSMANAGER_H
#define CAPITALISM_AGENTSMANAGER_H

#include <vector>
#include "Base/Manager.h"
#include "Simulation/Agent.h"

class AgentsManager: public Manager
{
public:
	virtual void update(float dt);
	
	void addNew(Agent* agent);
	const std::vector<Agent*> &getAgents() const;
	
	Manager* getSimulationManager() const;
	void setSimulationManager(Manager* simulationManager);

protected:
	std::vector<Agent*> agents;
	Manager* simulationManager;
};


#endif //CAPITALISM_AGENTSMANAGER_H
