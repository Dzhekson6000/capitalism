#ifndef CAPITALISM_BUILDINGS_H
#define CAPITALISM_BUILDINGS_H

#include "ui/CocosGUI.h"

class Buildings: public cocos2d::ui::ScrollView
{
private:
	Buildings();
	bool init();
	
	bool initIconBuilding();
public:
	CREATE_FUNC(Buildings);
};


#endif //CAPITALISM_BUILDINGS_H
