#include <View/ViewManager.h>
#include "GameScene.h"
#include "View/Ui/buildings/Buildings.h"
#include "Model/Map/Camera.h"
#include "Manager/BuildingTypeManager.h"

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
	
	this->scheduleUpdate();//начинаем обновлять постоянно
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin      = Director::getInstance()->getVisibleOrigin();
	
	//загружаем спрайты
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/tiles.plist");
	
	world = World::create();
	world->load("maps/test");
	this->addChild(world);
	
	//указываем всем виюхам текущий мир
	ViewManager::getInstance()->setWorld(world);
	
	//UI
	auto buildings = Buildings::create();
	buildings->setContentSize(Size(100, visibleSize.height));
	this->addChild(buildings);
	
	initKeyboard();
	
	return true;
}

void GameScene::initKeyboard()
{
	keyboardController.addCallback(
			EventKeyboard::KeyCode::KEY_Q,
			[this]()
			{
				::Camera::getInstance()->rotationLeft();
				world->updateIsoPoints();
			}
	);
	keyboardController.addCallback(
			EventKeyboard::KeyCode::KEY_E,
			[this]()
			{
				::Camera::getInstance()->rotationRight();
				world->updateIsoPoints();
			}
	);
	
	keyboardController.addCallback(
			EventKeyboard::KeyCode::KEY_KP_PLUS,
			[this]()
			{
				world->setScale(world->getScale()*1.1);//zoom +10%
			}
	);
	
	keyboardController.addCallback(
			EventKeyboard::KeyCode::KEY_KP_MINUS,
			[this]()
			{
				world->setScale(world->getScale()*0.9);//zoom -10%
			}
	);
	
	keyboardController.addCallback(
			EventKeyboard::KeyCode::KEY_SPACE,
			[this]()
			{
				std::string img = "trade:shop1";
				TypeBuilding* typeBuilding = BuildingTypeManager::getInstance()->
						getTypeBuilding(img);
				Building* ret = Building::create();
				ret->setId(4);
				ret->setTypeBuilding(typeBuilding);
				ret->setIsoPoint(IsoPoint(2, 2));
				ret->initObject();
				world->getLayerManager()->addMapObject(ret);
				world->getBuildingManager()->build(ret);
			}
	);
}

void GameScene::update(float delta)
{
	Node::update(delta);
	
	if( keyboardController.isKeyPressed(EventKeyboard::KeyCode::KEY_W))
	{
		world->move(Point(0,-10));
	}
	else if( keyboardController.isKeyPressed(EventKeyboard::KeyCode::KEY_S))
	{
		world->move(Point(0,10));
	}
	
	if( keyboardController.isKeyPressed(EventKeyboard::KeyCode::KEY_A))
	{
		world->move(Point(10,0));
	}
	else if( keyboardController.isKeyPressed(EventKeyboard::KeyCode::KEY_D))
	{
		world->move(Point(-10,0));
	}
	
	world->update(delta);
}
