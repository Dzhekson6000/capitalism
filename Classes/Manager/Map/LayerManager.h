#ifndef CAPITALISM_LAYERMANAGER_H
#define CAPITALISM_LAYERMANAGER_H

#include "Base/Manager.h"
#include "Model/Map/World/GroupObject.h"

class LayerManager: public Manager
{
public:
	LayerManager(Layer* world);
	
	void addMapObject(MapObject* mapObject);
	void updateInvisible();
	void updateIsoPoints();
	void setSizeGroup(const cocos2d::Size& size);
private:
	Layer* layer;
	
	GroupObject* objects; ///<  объекты(постройки и деревья)
	GroupObject* tiles;///<тайлы
};


#endif //CAPITALISM_LAYERMANAGER_H
