#ifndef CAPITALISM_SCROLLER_H
#define CAPITALISM_SCROLLER_H

#include "cocos2d.h"

class Scroller:public cocos2d::Layer
{
private:
	void initTouch();
	cocos2d::EventListenerTouchOneByOne* _touchListener;
	
	bool  _moved;
	float _xPosition;
	float _yPosition;
	cocos2d::Point _offsetPoint;

public:
	virtual bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void touchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void touchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual bool init();
	bool isScrollMap(cocos2d::Touch* touch, const cocos2d::Point point);
	bool  _notScroll;
	
	CREATE_FUNC(Scroller);
};

#endif //CAPITALISM_SCROLLER_H
