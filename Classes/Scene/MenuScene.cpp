#include "MenuScene.h"
#include "View/Ui/Button.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
	return MenuScene::create();
}

MenuScene::MenuScene()
{
}

bool MenuScene::init()
{
	if( !Scene::init())
	{
		return false;
	}
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin      = Director::getInstance()->getVisibleOrigin();
	
	auto button = Button::create();
	
	button->setTitleText("Game Scene");
	button->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	
	button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
		switch (type)
		{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				Director::getInstance()->replaceScene(GameScene::createScene());
				break;
			default:
				break;
		}
	});
	
	this->addChild(button);
	
	return true;
}



