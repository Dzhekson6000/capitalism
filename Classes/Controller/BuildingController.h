#ifndef CAPITALISM_BUILDINGCONTROLLER_H
#define CAPITALISM_BUILDINGCONTROLLER_H

#include "cocos2d.h"
#include "Model/Map/World.h"
#include "Model/Map/MapObject.h"

USING_NS_CC;

class BuildingController
{
public:
	static BuildingController* getInstance();
	
	/**
	 * Функция вызывает при выборе объекта для строительства
	 *
	 * @param groupName из какой группы объект
	 * @param objectName имя объекта
	 */
	void onSelectItem(std::string groupName, std::string objectName);
	
	/**
	 * @brief событие перемещение мыши
	 * @details изменяем позицию строющегося объекта
	 * @param event
	 */
	void onMouseMove(Event* event);
	
	/**
	 * @brief указываем строим ли бы объект или нет
	 * @details если true создаётся строющийся объекта инициализируется слушатеь,
	 *  если false удаляется объекта и слушатель
	 * @param buildingMode
	 */
	void setBuildingMode(bool buildingMode);
	bool getBuildingMode();
	
	void onClick();
	
	CC_SYNTHESIZE(std::string, _objectName, ObjectName);
	CC_SYNTHESIZE(std::string, _groupName,GroupName);
	CC_SYNTHESIZE(World*, _world, World)
private:
	static BuildingController* _buildingController;
	BuildingController();
	~BuildingController();
	
	EventListenerMouse* _mouseListener;
	/**
	 * Функция привязывающая строющийся объект к мыши
	 */
	void initMouseEvent();
	/**
	 * Функция отвязывающая строющийся объект от мыши
	 */
	void clearMouseEvent();
	
	bool _buildingMode; ///< true = строим объект
	EventDispatcher* _eventDispatcher;
	MapObject* _object; ///< объект который строим
	
};


#endif //CAPITALISM_BUILDINGCONTROLLER_H
