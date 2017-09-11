#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class MenuScene:public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	
	virtual bool init();
	
	virtual bool TouchBegan(Touch* touch, Event* event);
	virtual void TouchEnded(Touch* touch, Event* event);
	
	CREATE_FUNC(MenuScene);
private:
	EventListenerTouchOneByOne* _touchListener;
	
};

#endif // __MENU_SCENE_H__
