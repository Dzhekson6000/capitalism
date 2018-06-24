#include "ViewManager.h"

ViewManager* ViewManager::viewManager = nullptr;

ViewManager* ViewManager::getInstance()
{
	if( viewManager == nullptr )
	{
		viewManager = new ViewManager();
	}
	return viewManager;
}

ViewManager::ViewManager():ManagerWorld(nullptr)
{}
