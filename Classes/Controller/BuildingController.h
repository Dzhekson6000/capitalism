#ifndef CAPITALISM_BUILDINGCONTROLLER_H
#define CAPITALISM_BUILDINGCONTROLLER_H

#include "cocos2d.h"
#include "Model/Map/World.h"

USING_NS_CC;

class BuildingController
{
public:
	static BuildingController* getInstance();
	
	void onSelectItem(std::string groupName, std::string objectName);
	
	void onMouseMove(Event* event);
	void setBuildingMode(bool buildingMode);
	
	CC_SYNTHESIZE(std::string, _objectName, ObjectName);
	CC_SYNTHESIZE(std::string, _groupName,GroupName);
	CC_SYNTHESIZE(World*, _world, World)
private:
	static BuildingController* _buildingController;
	BuildingController();
	~BuildingController();
	
	void initMouseEvent();
	void clearMouseEvent();
	
	bool _buildingMode;
	EventDispatcher* _eventDispatcher;
	EventListenerMouse* _mouseListener;
};


#endif //CAPITALISM_BUILDINGCONTROLLER_H
