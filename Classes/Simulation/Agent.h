#ifndef CAPITALISM_AGENT_H
#define CAPITALISM_AGENT_H

#include "Message.h"

class Agent
{
public:
	Agent();
	virtual bool message(Message& message);
};


#endif //CAPITALISM_AGENT_H
