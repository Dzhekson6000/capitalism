#ifndef CAPITALISM_SCROLLER_H
#define CAPITALISM_SCROLLER_H

#include "cocos2d.h"
#include "Model/Map/IsoPoint.h"

class Scroller:public cocos2d::Layer
{
private:
	cocos2d::EventListenerTouchOneByOne* _touchListener;
	
	bool           _isMoving; ///< true = идёт перемещение карты
	cocos2d::Point _offsetPoint; ///< временная переменная что бы фиксировать СУЩЕСТВЕННОЕ смещение
	
	/**
	 * фукция проверки нахождения точки в окне
	 * @param point точка
	 * @return true если в окне
	 */
	bool inWindow(const cocos2d::Point &point);
	
	/**
	 * функция что бы отличать нажатия от перетаскивания
	 * @param touch
	 * @param point
	 * @return true = если перетаскивание
	 */
	bool isScrollMap(cocos2d::Point &touch, const cocos2d::Point point);
	
	
	bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void touchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void touchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
protected:
	/**
	 * событие перемещения
	 */
	virtual void onMove(){};
	
	/**
 * событие клика
 * @param point клетка по которой совершён клик
 */
	virtual void onClick(const cocos2d::Point point);
public:
	CREATE_FUNC(Scroller);
	/**
	 * инициализация, создание слушателей
	 * @return true = ok, false = error
	 */
	virtual bool init();
	
	/**
	 * @brief функция перемещения карты
	 * @param offset параметр смещения
	 */
	void move(const cocos2d::Point offset);
	
	/**
	* смещение относительно текущего положения
	* @param point
	* @return возвращаем смещение
	*/
	cocos2d::Point getOffsetPoint(const cocos2d::Point point);
	
};

#endif //CAPITALISM_SCROLLER_H
