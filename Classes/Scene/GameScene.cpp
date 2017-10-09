#include "GameScene.h"
#include "Controller/LoaderConfig.h"
#include "Model/Map/World.h"
#include "Controller/LoaderMap.h"
#include "View/Ui/Buildings.h"

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
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin      = Director::getInstance()->getVisibleOrigin();
	
	LoaderConfig loaderConfig;
	loaderConfig.loadConfigFile("configs/sprites.xml");
	
	auto world = World::create();
	this->addChild(world);
	
	LoaderMap* map = new LoaderMap(world);
	map->loadMap("maps/moscow.png");
	//map->loadMapObject("maps/moscow.xml");
	map->draw();
	
	
	//UI
	auto buildings = Buildings::create();
	buildings->setContentSize(Size(100,visibleSize.height));
	addChild(buildings);
	
	return true;
}
