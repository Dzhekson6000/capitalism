#ifndef CAPITALISM_ITEMBUILDING_H
#define CAPITALISM_ITEMBUILDING_H

#include "ui/CocosGUI.h"

class ItemBuilding: public cocos2d::ui::Button
{
public:
	bool initWithSpriteFrame(cocos2d::SpriteFrame* spriteFrame);
	
	CREATE_FUNC(ItemBuilding);
};


#endif //CAPITALISM_ITEMBUILDING_H
