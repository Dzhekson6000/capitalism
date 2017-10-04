#include "Buildings.h"
#include <Tools/TileImageManager.h>

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
	TileImageManager::GroupsType gp = TileImageManager::getInstance()->getGroups();
	for(auto group: gp)
	{
		if(group.first == "tiles")
			continue;
		
		for(auto sprite: group.second->sprites)
		{
			Sprite* icon = Sprite::createWithSpriteFrame(sprite.second->frames[0]);
			icon->setPosition(50, y);
			icon->setScale(std::min(100/icon->getContentSize().width, 100/icon->getContentSize().height));
			y+=icon->getContentSize().height*icon->getScale();
			addChild(icon);
		}
	}
	
	setInnerContainerSize(Size(100,y));
	
	return true;
}