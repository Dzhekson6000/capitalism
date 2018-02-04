#ifndef CAPITALISM_GROUPOBJECT_H
#define CAPITALISM_GROUPOBJECT_H

#include "cocos2d.h"
#include "MapObject.h"

USING_NS_CC;


/**
 * Класс представляющий внутри себя дерево групп объектов с группой максимальной области 10х10
 */
class GroupObject: public Layer
{
public:
	CREATE_FUNC(GroupObject)
	
	/**
	 * добавление объекта
	 * @param object
	 */
	void addObject(MapObject* object);
	
	/**
	 * удаление объекта
	 * @param object
	 */
	void removeObject(MapObject* object);
	
	void updateInvisible(const Point& offset);
	
	/**
	 * рекурсивно ищет GroupObject
	 * @param cell координаты изометрической клетки принадежащие искомому GroupObject
	 * @return GroupObject или nullptr
	 */
	GroupObject* findGroupObject(Point cell);
	
	/**
	 * ищет среди детей субгруппы
	 * @param point координаты изометрической клетки принадежащие искомому GroupObject
	 * @return GroupObject или nullptr
	 */
	GroupObject* findSubGroupObject(Point point);
	
	/**
	 * Ищет GroupObject и если не находит создаёт его.
	 * @param cell координаты изометрической клетки принадежащие искомому @GroupObject
	 * @return GroupObject или nullptr в случае если он выходит за пределы группы
	 */
	GroupObject* getGroupObject(Point cell);
	
	/**
	 * создаёт GroupObject для заданной точки
	 * @param point изометрическая точка
	 * @return созданный GroupObject или nullptr если выходит за пределый группы
	 */
	GroupObject* createGroupObject(Point point);
	
	/**
	 * @param point позиция карты
	 * @return true если группа видна
	 */
	bool isVisible(const Point point) const;
	
	/**
	 * @param point точка в изометрии
	 * @return true если точка внутри группы
	 */
	bool isBoundingBoxCell(const Point point) const;
	
	CC_SYNTHESIZE(Size, _size, SizeGroup);
	CC_SYNTHESIZE(IsoPoint, _isoPoint, IsoPoint);
private:
	GroupObject();
};



#endif //CAPITALISM_GROUPOBJECT_H
