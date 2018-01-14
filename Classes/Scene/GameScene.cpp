#include "GameScene.h"
#include "Model/Map/World.h"
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
	
	//загружаем спрайты
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/tiles.plist");
	
	auto world = World::create();
	world->loadMap("maps/test.png");
	world->loadMapObject("maps/test.xml");
	this->addChild(world);
	
	
	//UI
	/*auto buildings = Buildings::create();
	buildings->setContentSize(Size(100, visibleSize.height));
	addChild(buildings);*/
	
	return true;
}
