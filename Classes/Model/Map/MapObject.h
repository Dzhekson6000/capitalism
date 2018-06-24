#ifndef CAPITALISM_MAPOBJECT_H
#define CAPITALISM_MAPOBJECT_H

#include "IsoPoint.h"
#include "cocos2d.h"

USING_NS_CC;

class GroupObject;

/**
 * Класс объекта карты. Все тайлы и спрайты на карте это объекты.
 */
class MapObject:public Sprite
{
public:
	CREATE_FUNC(MapObject)
	
	enum class Type
	{
		NONE,
		LANDSCAPE,
		BUILDING
	};
	
	/**
	 * инициализация объекта. тут загрузка изображения объекта.
	 * @return
	 */
	virtual bool initObject();
	
	/**
	 * Удаление из уровня отображения
	 */
	void removeFromLayer();
	
	/**
	 * функция обновляет позицию объекта
	 */
	void updateIsoPoint();
	
	/**
	 * @brief рисует текст поверх объекта
	 * @param text
	 */
	void printDebugCell(std::string text);

protected:
	MapObject();
	
	IsoPoint isoPoint;///< координаты объекта
	Type type;
	int wCell;
	int hCell;
	
	std::string group;
	std::string name;
	int frame;
	
private:
	Layer* groupObject;
	Label* label;

public:
	virtual int getFrame() const;
	
	const IsoPoint &getIsoPoint() const;
	void setIsoPoint(const IsoPoint &isoPoint);
	
	Type getType() const;
	void setType(Type type);
	
	const std::string &getGroup() const;
	void setGroup(const std::string &group);
	
	const std::string &getName() const;
	void setName(const std::string &name);
	
	Layer* getGroupObject() const;
	void setGroupObject(Layer* groupObject);
};


#endif //CAPITALISM_MAPOBJECT_H
