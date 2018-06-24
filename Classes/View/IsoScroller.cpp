#include "IsoScroller.h"
#include "Manager/Map/BuildingManager.h"

USING_NS_CC;

bool IsoScroller::init()
{
	setAnchorPoint(Point(0, 0));
	
	auto     size = cocos2d::Director::getInstance()->getWinSize();
	_cameraPosition.initOfScreen(-(Point)(size/2));
	
	return Scroller::init();
}

void IsoScroller::setPosition(const cocos2d::Vec2 &position)
{
	Scroller::setPosition(position);
	
	auto     size = cocos2d::Director::getInstance()->getWinSize();
	_cameraPosition.initOfScreen(position - size/2);
}

void IsoScroller::updateIsoPoints()
{
	auto     size = cocos2d::Director::getInstance()->getWinSize();
	_cameraPosition.updateScreen();
	Scroller::setPosition(_cameraPosition + size/2);
}

void IsoScroller::onClick(const cocos2d::Point point)
{
	Point    p = (point - getPosition())/getScale();
	
	IsoPoint offset;
	offset.initOfScreen(p.x, p.y);
	onClickCell(offset);
	
	Scroller::onClick(point);
}

void IsoScroller::onClickCell(const IsoPoint& point)
{
	Point cell = point.getCell();
	CCLOG("Click (%f, %f)", cell.x, cell.y);
	
}

void IsoScroller::setScale(float scale)
{
	//пытаемся отцентровать
	float dScale = getScale()-scale;
	setPositionX(getPositionX() + getContentSize().width/2*dScale);
	setPositionY(getPositionY() + getContentSize().height/2*dScale);
	
	Node::setScale(scale);
	onMove();
}
