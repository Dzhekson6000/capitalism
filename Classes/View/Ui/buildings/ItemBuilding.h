#ifndef CAPITALISM_ITEMBUILDING_H
#define CAPITALISM_ITEMBUILDING_H

#include "ui/CocosGUI.h"
#include "Base/ViewWorld.h"

class ItemBuilding: public cocos2d::ui::Button, public ViewWorld
{
public:
	bool initWithSpriteFrame(cocos2d::SpriteFrame* spriteFrame);
	
	CREATE_FUNC(ItemBuilding);
	CC_SYNTHESIZE(std::string, _objectName, ObjectName);
	CC_SYNTHESIZE(std::string, _groupName,GroupName);
};


#endif //CAPITALISM_ITEMBUILDING_H
