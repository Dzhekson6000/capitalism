#ifndef CAPITALISM_MANAGERWORLD_H
#define CAPITALISM_MANAGERWORLD_H

#include "Manager.h"
#include "Model/Map/World/World.h"

class ManagerWorld:public Manager
{
public:
	explicit ManagerWorld(World* world);
	
	World* getWorld() const;
	void setWorld(World* world);

protected:
	World* world;///< мир в которым управляем
};


#endif //CAPITALISM_MANAGERWORLD_H
