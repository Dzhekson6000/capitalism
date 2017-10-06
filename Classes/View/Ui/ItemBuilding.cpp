#include "ItemBuilding.h"

USING_NS_CC;

bool ItemBuilding::initWithSpriteFrame(cocos2d::SpriteFrame* spriteFrame)
{
	loadTextureNormal(spriteFrame);
	addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
		switch (type)
		{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				CCLOG("Click to %s:%s",_groupName.c_str(), _objectName.c_str());
				break;
			default:
				break;
		}
	});
	return true;
}
