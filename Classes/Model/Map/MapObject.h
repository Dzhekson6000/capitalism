#ifndef CAPITALISM_MAPOBJECT_H
#define CAPITALISM_MAPOBJECT_H

#include "Model/IsoPoint.h"
#include "cocos2d.h"

USING_NS_CC;

class MapObject:public Sprite
{
public:
	CC_SYNTHESIZE(int, _id, IdTile);
	CC_SYNTHESIZE(int, _width, WidthTile);
	CC_SYNTHESIZE(int, _length, LengthTile);
	CC_SYNTHESIZE(int, _height, HeightTile);

	CC_SYNTHESIZE(std::string, _group, GroupTile);
	CC_SYNTHESIZE(std::string, _name, NameTile);
	
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
	
	CREATE_FUNC(MapObject)
protected:
	MapObject();
};


#endif //CAPITALISM_MAPOBJECT_H
