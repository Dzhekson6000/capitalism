#include "GameScene.h"
#include "View/Ui/buildings/Buildings.h"
#include "Model/Camera.h"

cocos2d::Scene* GameScene::createScene()
{
	return GameScene::create();
}

bool GameScene::init()
{
	if( !Scene::init())
	{
		return false;
	}
	
	this->scheduleUpdate();
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin      = Director::getInstance()->getVisibleOrigin();
	
	//загружаем спрайты
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/tiles.plist");
	
	_world = World::create();
	_world->loadMap("maps/test.png");
	_world->loadMapObject("maps/test.xml");
	this->addChild(_world);
	
	
	//UI
	/*
	TODO::временно уберём
	auto buildings = Buildings::create();
	buildings->setContentSize(Size(100, visibleSize.height));
	addChild(buildings);*/
	
	//вращение камеры
	_keyboardController.addCallback(
			EventKeyboard::KeyCode::KEY_Q,
			[this]()
			{
				::Camera::getInstance()->rotationLeft();
				_world->updateIsoPoints();
			}
	);
	_keyboardController.addCallback(
			EventKeyboard::KeyCode::KEY_E,
			[this]()
			{
				::Camera::getInstance()->rotationRight();
				_world->updateIsoPoints();
			}
	);
	
	return true;
}

void GameScene::update(float delta)
{
	Node::update(delta);
	
	if( _keyboardController.isKeyPressed(EventKeyboard::KeyCode::KEY_W))
	{
		_world->move(Point(0,-10));
	}
	else if( _keyboardController.isKeyPressed(EventKeyboard::KeyCode::KEY_S))
	{
		_world->move(Point(0,10));
	}
	
	if( _keyboardController.isKeyPressed(EventKeyboard::KeyCode::KEY_A))
	{
		_world->move(Point(10,0));
	}
	else if( _keyboardController.isKeyPressed(EventKeyboard::KeyCode::KEY_D))
	{
		_world->move(Point(-10,0));
	}
}
