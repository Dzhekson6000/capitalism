#include "Buildings.h"
#include "cocos2d.h"
#include "ItemBuilding.h"
#include "Manager/BuildingTypeManager.h"

USING_NS_CC;

Buildings::Buildings()
{
	
}

bool Buildings::init()
{
	if(!ui::ScrollView::init())
	{
		return false;
	}
	
	setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
	setBackGroundColor(Color3B::ORANGE);
	
	setBounceEnabled(false);
	setTouchEnabled(true);
	
	initIconBuilding();
	
	return true;
}

bool Buildings::initIconBuilding()
{
	int y = 0;
	auto types = BuildingTypeManager::getInstance()->getTypesBuilding();
	for(std::pair<std::string, TypeBuilding*> type: types)
	{
		std::string filename = type.second->group + "/" + type.second->name + "/1.png";
		
		auto newspriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(filename);
		
		ItemBuilding* icon = ItemBuilding::create();
		icon->initWithSpriteFrame(newspriteFrame);
		icon->setGroupName(type.second->group);
		icon->setObjectName(type.second->name);
		icon->setPosition(Vec2(50, y));
		icon->setScale(std::min(100/icon->getContentSize().width, 100/icon->getContentSize().height));
		y+=icon->getContentSize().height*icon->getScale();
		addChild(icon);
		
	}
	
	setInnerContainerSize(Size(100,y));
	
	return true;
}