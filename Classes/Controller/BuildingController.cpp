#include "BuildingController.h"
#include "Controller/TileImageManager.h"

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
	_groupName = groupName;
	_objectName = objectName;
	setBuildingMode(true);
}

void BuildingController::onMouseMove(Event* event)
{
	EventMouse* e = (EventMouse*)event;
	Point point(e->getCursorX(),e->getCursorY());
	point.y+=Director::getInstance()->getVisibleSize().height;
	Point pointRelativeWorld = _world->getOffsetPoint(point);
	IsoPoint iso;
	iso.screenToIso(pointRelativeWorld.x, pointRelativeWorld.y);
	iso.reductionToCell();
	_object->setIsoPoint(iso);
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
		_object=MapObject::create();
		_object->setGroupTile(_groupName);
		_object->setNameTile(_objectName);
		_object->initObject();
		_world->addObject(_object);
	}
	else
	{
		clearMouseEvent();
		_world->removeObject(_object);
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
