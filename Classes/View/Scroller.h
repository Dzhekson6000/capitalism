#ifndef CAPITALISM_SCROLLER_H
#define CAPITALISM_SCROLLER_H

#include "cocos2d.h"
#include "Model/IsoPoint.h"

class Scroller:public cocos2d::Layer
{
private:
	cocos2d::EventListenerTouchOneByOne* _touchListener;
	
	bool  _isMoving;
	cocos2d::Point _offsetPoint;
	
	bool inWindow(const cocos2d::Point &point);
	
public:
	bool touchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void touchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void touchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	
	virtual void onClick(const cocos2d::Point point);
	cocos2d::Point getOffsetPoint(const cocos2d::Point point);
	
	virtual bool init();
	bool isScrollMap(cocos2d::Point &touch, const cocos2d::Point point);
	
	CREATE_FUNC(Scroller);
};

#endif //CAPITALISM_SCROLLER_H
