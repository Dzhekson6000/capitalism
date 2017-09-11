#ifndef CAPITALISM_GAMESCENE_H
#define CAPITALISM_GAMESCENE_H

#include "cocos2d.h"

USING_NS_CC;

class GameScene:public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	
	virtual bool init();
		
	CREATE_FUNC(GameScene);
};


#endif //CAPITALISM_GAMESCENE_H
