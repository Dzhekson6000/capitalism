#ifndef CAPITALISM_VIEWMANAGER_H
#define CAPITALISM_VIEWMANAGER_H

#include "Base/ManagerWorld.h"

class ViewManager: public ManagerWorld
{
public:
	static ViewManager* getInstance();

private:
	ViewManager();
	
	static ViewManager* viewManager;
	
	
};


#endif //CAPITALISM_VIEWMANAGER_H
