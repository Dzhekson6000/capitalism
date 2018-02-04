#ifndef CAPITALISM_SCROLLER_H
#define CAPITALISM_SCROLLER_H

#include "cocos2d.h"
#include "Model/IsoPoint.h"

class Scroller:public cocos2d::Layer
{
private:
	cocos2d::EventListenerTouchOneByOne* _touchListener;
	
	bool  _isMoving; ///< true = идёт перемещение карты
	cocos2d::Point _offsetPoint; ///< временная переменная что бы фиксировать СУЩЕСТВЕННОЕ смещение
	
	/**
	 * фукция проверки нахождения точки в окне
	 * @param point точка
	 * @return true если в окне
	 */
	bool inWindow(const cocos2d::Point &point);

protected:
	/**
	 * событие перемещения
	 */
	virtual void onMove(){};
	
public:
	bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void touchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void touchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	
	/**
	 * @brief функция перемещения карты по X
	 * @param offset параметр смещения
	 */
	void moveX(float offset);
	
	/**
	 * @brief функция перемещения карты по X
	 * @param offset параметр смещения
	 */
	void moveY(float offset);
	
	/**
	 * событие клика
	 * @param point клетка по которой совершён клик
	 */
	virtual void onClick(const cocos2d::Point point);
	/**
	 * смещение относительно текущего положения
	 * @param point
	 * @return возвращаем смещение
	 */
	cocos2d::Point getOffsetPoint(const cocos2d::Point point);
	
	/**
	 * инициализация, создание слушателей
	 * @return true = ok, false = error
	 */
	virtual bool init();
	
	/**
	 * функция что бы отличать нажатия от перетаскивания
	 * @param touch
	 * @param point
	 * @return true = если перетаскивание
	 */
	bool isScrollMap(cocos2d::Point &touch, const cocos2d::Point point);
	
	CREATE_FUNC(Scroller);
};

#endif //CAPITALISM_SCROLLER_H
