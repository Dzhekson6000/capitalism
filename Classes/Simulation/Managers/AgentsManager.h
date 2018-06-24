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

private:
	std::vector<Agent*> agents;
};


#endif //CAPITALISM_AGENTSMANAGER_H
