#ifndef CAPITALISM_SCROLLER_H
#define CAPITALISM_SCROLLER_H

#include "cocos2d.h"

USING_NS_CC;

class Scroller:public Layer
{
private:
	void initTouch();
	EventListenerTouchOneByOne* _touchListener;
	
	bool  _moved;
	float _xPosition;
	float _yPosition;
	Point _offsetPoint;

public:
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);
	virtual bool init();
	bool isScrollMap(Touch* touch, const Point point);
	bool  _notScroll;
	
	CREATE_FUNC(Scroller);
};

#endif //CAPITALISM_SCROLLER_H
