#include <Model/Map/IsoPoint.h>
#include "Scroller.h"
#include "Model/Config.h"

USING_NS_CC;

bool Scroller::init()
{
	if( !Layer::init())
	{
		return false;
	}
	
	_isMoving = false;
	
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
	
	if( isScrollMap(loc, _offsetPoint))
	{
		move(loc-_offsetPoint);
		_offsetPoint = loc;
		_isMoving    = true;
	}
	
}

void Scroller::touchEnded(Touch* touch, Event* event)
{
	if( _isMoving )
	{
		_isMoving = false;
	}
	else
	{
		onClick(touch->getLocation());
	}
}

void Scroller::move(const cocos2d::Point offset)
{
	this->setPosition(this->getPosition() + offset);
	onMove();
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
	return (
			std::abs(point.x - touch.x) > Config::SENSITIVITY_SCROLL ||
			std::abs(point.y - touch.y) > Config::SENSITIVITY_SCROLL
	);
}

void Scroller::onClick(const cocos2d::Point point)
{
}

Point Scroller::getOffsetPoint(const cocos2d::Point point)
{
	return point - getPosition();
}
