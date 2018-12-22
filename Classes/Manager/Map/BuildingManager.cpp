#include "BuildingManager.h"
#include "Manager/BuildingTypeManager.h"
#include "Loader/Map/LoaderTypeBuildings.h"
#include "Model/Map/Building/Building.h"


BuildingManager::BuildingManager(LayerManager* layerManager, IsoScroller* isoScroller, BuildingAManager* buildingAManager):
		layerManager(layerManager),
		isoScroller(isoScroller),
		buildingAManager(buildingAManager),
		_mouseListener(nullptr),
		_buildingMode(false)
{
	_eventDispatcher = Director::getInstance()->getEventDispatcher();
	
	//загружаем типы построек
	LoaderTypeBuildings loaderTypeBuildings;
	loaderTypeBuildings.load("configs/types_building.xml");
}

BuildingManager::~BuildingManager()
{
	clearMouseEvent();
}

void BuildingManager::onSelectItem(std::string groupName, std::string objectName)
{
	_groupName  = groupName;
	_objectName = objectName;
	if(_buildingMode)
		setBuildingMode(false);
	setBuildingMode(true);
}

void BuildingManager::onMouseMove(Event* event)
{
	Point point(((EventMouse*)event)->getCursorX(), ((EventMouse*)event)->getCursorY());
	point.y += Director::getInstance()->getVisibleSize().height;
	
	Point pointRelativeWorld = isoScroller->getOffsetPoint(point);
	
	IsoPoint iso;
	iso.initOfScreen(pointRelativeWorld.x, pointRelativeWorld.y);
	iso.reductionToCell();
	
	//обновляем позицию
	_object->retain();
	_object->removeFromLayer();
	_object->setIsoPoint(iso);
	layerManager->addMapObject(_object);
	_object->release();
}

void BuildingManager::setBuildingMode(bool buildingMode)
{
	if( _buildingMode == buildingMode )
	{
		return;
	}
	
	if( buildingMode )
	{
		initMouseEvent();
		
		std::string type = _groupName + ":" + _objectName;
		TypeBuilding* typeBuilding = BuildingTypeManager::getInstance()->getTypeBuilding(type);
		
		if( !typeBuilding )
		{
			return;
		}
		
		_object = Building::create();
		((Building*)_object)->setTypeBuilding(typeBuilding);
		
		_object->initObject();
		layerManager->addMapObject(_object);
	}
	else
	{
		clearMouseEvent();
		build((Building*)_object);
		_object = nullptr;
	}
	_buildingMode = buildingMode;
	
}

bool BuildingManager::getBuildingMode()
{
	return _buildingMode;
}

void BuildingManager::onClick()
{
	setBuildingMode(false);
}

void BuildingManager::initMouseEvent()
{
	if( !_mouseListener )
	{
		_mouseListener = EventListenerMouse::create();
		_mouseListener->onMouseMove = CC_CALLBACK_1(BuildingManager::onMouseMove, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, isoScroller);
	}
}

void BuildingManager::clearMouseEvent()
{
	if( _mouseListener )
	{
		_eventDispatcher->removeEventListener(_mouseListener);
		_mouseListener = nullptr;
	}
}

void BuildingManager::build(Building* buildObject)
{
	//создём агента для постройки
	buildingAManager->addNew(buildingAManager->createBuildingAgent(buildObject));
}
