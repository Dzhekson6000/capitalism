#include "Buildings.h"
#include <Controller/TileImageManager.h>
#include "View/Ui/ItemBuilding.h"

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
			
			ItemBuilding* icon = ItemBuilding::create();
			icon->initWithSpriteFrame(sprite.second->frames[0]);
			icon->setGroupName(group.first);
			icon->setObjectName(sprite.first);
			icon->setPosition(Vec2(50, y));
			icon->setScale(std::min(100/icon->getContentSize().width, 100/icon->getContentSize().height));
			y+=icon->getContentSize().height*icon->getScale();
			addChild(icon);
		}
	}
	
	setInnerContainerSize(Size(100,y));
	
	return true;
}