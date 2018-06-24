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
	
	auto fon = Sprite::create("ui/menu_fon.jpg");
	fon->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	fon->setScale(
			MAX(
					visibleSize.width / fon->getContentSize().width,
					visibleSize.height / fon->getContentSize().height)
	);
	this->addChild(fon);
	
	auto play_button = Button::create(Button::WidgetType::BUTTON, Button::Color::BLUE);
	play_button->setTitleText("Play");
	play_button->addTouchEventListener(
			[&](Ref* sender, ui::Widget::TouchEventType type)
			{
				switch( type )
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
	
	
	auto setting_button = Button::create(Button::WidgetType::BUTTON, Button::Color::BLUE);
	setting_button->setTitleText("Settings");
	setting_button->addTouchEventListener(
			[&](Ref* sender, ui::Widget::TouchEventType type)
			{
				switch( type )
				{
					case ui::Widget::TouchEventType::BEGAN:
						break;
					case ui::Widget::TouchEventType::ENDED:
						//Director::getInstance()->replaceScene(SettingScene::createScene());
						break;
					default:
						break;
				}
			});
	
	
	auto exit_button = Button::create(Button::WidgetType::BUTTON, Button::Color::BLUE);
	exit_button->setTitleText("Exit");
	exit_button->addTouchEventListener(
			[&](Ref* sender, ui::Widget::TouchEventType type)
			{
				switch( type )
				{
					case ui::Widget::TouchEventType::BEGAN:
						break;
					case ui::Widget::TouchEventType::ENDED:
						Director::getInstance()->end();
						break;
					default:
						break;
				}
			});
	
	
	play_button->setPosition(
			Vec2(visibleSize.width/2 + origin.x,
			     visibleSize.height/2 + origin.y + setting_button->getLayoutSize().height+20));
	setting_button->setPosition(
			Vec2(visibleSize.width/2 + origin.x,
			     visibleSize.height/2 + origin.y));
	exit_button->setPosition(
			Vec2(visibleSize.width/2 + origin.x,
			     visibleSize.height/2 + origin.y - setting_button->getLayoutSize().height-20));
	
	this->addChild(play_button);
	this->addChild(setting_button);
	this->addChild(exit_button);
	
	return true;
}



