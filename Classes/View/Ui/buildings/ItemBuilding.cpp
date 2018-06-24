#include "ItemBuilding.h"
#include "Manager/Map/BuildingManager.h"

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
				((BuildingManager*)getWorld()->getBuildingManager())->onSelectItem(/*_groupName*/"hs.modern", "grand"/*_objectName*/);
				break;
			default:
				break;
		}
	});
	return true;
}
