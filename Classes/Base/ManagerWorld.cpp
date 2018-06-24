#include "ManagerWorld.h"

ManagerWorld::ManagerWorld(World* world):
world(world)
{
}

World* ManagerWorld::getWorld() const
{
	return world;
}

void ManagerWorld::setWorld(World* world)
{
	ManagerWorld::world = world;
}

