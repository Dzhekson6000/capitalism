#include "GameScene.h"
#include "Controller/Loader/LoaderConfig.h"
#include "Model/Map/World.h"
#include "Controller/Loader/LoaderMap.h"
#include "Controller/Loader/LoaderMapObject.h"
#include "View/Ui/buildings/Buildings.h"

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
	
	LoaderMap loaderMap(world);
	loaderMap.loadMap("maps/moscow.png");
	
	LoaderMapObject loaderMapObject(world);
	loaderMapObject.loadMapObjectFile("maps/test.xml");
	
	loaderMap.draw();
	
	//UI
	auto buildings = Buildings::create();
	buildings->setContentSize(Size(100, visibleSize.height));
	addChild(buildings);
	
	return true;
}
