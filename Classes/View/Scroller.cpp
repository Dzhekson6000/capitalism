#include <Model/IsoPoint.h>
#include "Scroller.h"

USING_NS_CC;

bool Scroller::init()
{
	if( !Layer::init())
	{
		return false;
	}
	
	_isMoving  = false;
	
	// init touch
	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(Scroller::touchBegan, this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(Scroller::touchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(Scroller::touchEnded, this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 100);
	
	return true;
}

bool Scroller::touchBegan(Touch* touch, Event* event)
{
	_offsetPoint = touch->getLocation();
	return true;
}

void Scroller::touchMoved(Touch* touch, Event* event)
{
	Point loc = touch->getLocation();
	if( !inWindow(loc))
	{
		return;
	}
	
	if(isScrollMap(loc, _offsetPoint))
	{
		this->setPositionX(this->getPositionX() + (loc.x - _offsetPoint.x));
		this->setPositionY(this->getPositionY() + (loc.y - _offsetPoint.y));
		
		_offsetPoint=loc;
		_isMoving= true;
	}
	
}

void Scroller::touchEnded(Touch* touch, Event* event)
{
	if(_isMoving)
	{
		_isMoving=false;
	}
	else
	{
		onClick(touch->getLocation());
	}
}

bool Scroller::inWindow(const cocos2d::Vec2 &point)
{
	auto size = Director::getInstance()->getWinSize();
	if( point.x < 0 || point.x > size.width )
	{
		return false;
	}
	return true;
}

bool Scroller::isScrollMap(cocos2d::Point &touch, const Point point)
{
	return (std::abs(point.x - touch.x) > 20 ||
			std::abs(point.y - touch.y) > 20);
}

void Scroller::onClick(const cocos2d::Point point)
{
	Point p = point - getPosition();
	IsoPoint offset;
	offset.screenToIso(p.x,p.y);
	Point cell = offset.getCell();
	
	CCLOG("Click (%f, %f)", cell.x, cell.y);
}

Point Scroller::getOffsetPoint(const cocos2d::Point point)
{
	Point ret = point - getPosition();
	return ret;
}
