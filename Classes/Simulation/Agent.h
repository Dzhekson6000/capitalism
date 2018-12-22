#ifndef CAPITALISM_AGENT_H
#define CAPITALISM_AGENT_H

#include "Message.h"
#include "Base/Manager.h"
#include <unordered_map>

class Agent
{
public:
	class Message: public ::Message
	{
	public:
		Agent* sender;
	};
	
	Agent();
	virtual bool init();
	virtual bool message(Agent::Message& message);
	virtual void update(float dt);
	
	Manager* getSimulationManager() const;
	
	void setSimulationManager(Manager* simulationManager);
	
	const std::unordered_map<int, float> &getOwns() const;
	float getOwn(int id) const;
	void setOwn(int id, float volume);
protected:
	Manager* simulationManager;
	
	/** продукты или услуги которыми обладает агент
	 * 1 - популяция
	 * 2 - трудовые ресурсы
	 * 3 - финансы
	 * 4 - еда
	 */
	std::unordered_map<int, float> owns;
};


#endif //CAPITALISM_AGENT_H
