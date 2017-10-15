#include "BuildingController.h"

BuildingController* BuildingController::_buildingController = nullptr;

BuildingController* BuildingController::getInstance()
{
	if (_buildingController == nullptr)
	{
		_buildingController = new BuildingController();
	}
	return _buildingController;
}

BuildingController::BuildingController():
		_mouseListener(nullptr),
		_buildingMode(false)
{
	_eventDispatcher = Director::getInstance()->getEventDispatcher();
}

BuildingController::~BuildingController()
{
	clearMouseEvent();
}

void BuildingController::onSelectItem(std::string groupName, std::string objectName)
{
	
}

void BuildingController::onMouseMove(Event* event)
{
	EventMouse* e = (EventMouse*)event;
	std::string str = "MousePosition X:";
	str = str + std::to_string(e->getCursorX()) + " Y:" + std::to_string(e->getCursorY());
	//CCLOG(str.c_str());
}

void BuildingController::setBuildingMode(bool buildingMode)
{
	if(_buildingMode == buildingMode)
	{
		return;
	}
	
	if(buildingMode)
	{
		initMouseEvent();
	}
	else
	{
		clearMouseEvent();
	}
	_buildingMode=buildingMode;
	
}

void BuildingController::initMouseEvent()
{
	if( !_mouseListener )
	{
		_mouseListener = EventListenerMouse::create();
		_mouseListener->onMouseMove = CC_CALLBACK_1(BuildingController::onMouseMove, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, _world);
	}
}

void BuildingController::clearMouseEvent()
{
	if( _mouseListener )
	{
		_eventDispatcher->removeEventListener(_mouseListener);
		_mouseListener = nullptr;
	}
}
