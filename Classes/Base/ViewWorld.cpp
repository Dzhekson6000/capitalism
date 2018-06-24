#include "ViewWorld.h"
#include "View/ViewManager.h"

World* ViewWorld::getWorld() const
{
	return ViewManager::getInstance()->getWorld();
}
