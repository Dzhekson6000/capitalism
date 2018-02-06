#include "IsoScroller.h"

bool IsoScroller::init()
{
	auto     size = cocos2d::Director::getInstance()->getWinSize();
	_cameraPosition.initOfScreen(-(cocos2d::Point)(size/2));
	
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
