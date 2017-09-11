#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"


Scene* MenuScene::createScene()
{
	return MenuScene::create();
}

bool MenuScene::init()
{
	if( !Scene::init())
	{
		return false;
	}
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin      = Director::getInstance()->getVisibleOrigin();
	
	auto sprite = Sprite::create("menu.jpg");
	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(sprite, 0);
	
	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(MenuScene::TouchBegan,this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(MenuScene::TouchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 100);
	
	return true;
}

bool MenuScene::TouchBegan(Touch* touch, Event* event)
{
	return true;
}

void MenuScene::TouchEnded(Touch* touch, Event* event)
{
	Director::getInstance()->replaceScene(GameScene::createScene());
}


