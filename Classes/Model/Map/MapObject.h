#ifndef CAPITALISM_MAPOBJECT_H
#define CAPITALISM_MAPOBJECT_H

#include "Model/IsoPoint.h"
#include "cocos2d.h"

USING_NS_CC;

/**
 * Класс объекта карты. Все тайлы и спрайты на карте это объекты.
 */
class MapObject:public Sprite
{
public:
	CC_SYNTHESIZE(std::string, _group, GroupTile);
	CC_SYNTHESIZE(std::string, _name, NameTile);
	CC_SYNTHESIZE(int, _frame, FrameTile);
	
	/**
	 * инициализация объекта. тут загрузка изображения объекта.
	 * @return
	 */
	virtual bool initObject();
	
	/**
	 * указываем координаты объекта
	 * @param isoPoint
	 */
	void setIsoPoint(const IsoPoint isoPoint);
	CC_SYNTHESIZE_READONLY(IsoPoint, _isoPoint, IsoPoint);
	
	/**
	 * функция обновляет позицию объекта
	 */
	void updateIsoPoint();
	
	/**
	 * @brief рисует текст поверх объекта
	 * @param text
	 */
	void printDebugCell(std::string text);
	
	CREATE_FUNC(MapObject)
protected:
	MapObject();
};


#endif //CAPITALISM_MAPOBJECT_H
