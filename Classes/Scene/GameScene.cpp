#include "GameScene.h"
#include "Model/Map/MapCity.h"
#include "Model/Config.h"
#include "View/Scroller.h"
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
	
	Config* config = new Config();
	config->loadConfigFile("configs/sprites.xml");
	
	Scroller* scroller = Scroller::create();
	this->addChild(scroller);
	
	MapCity* map = new MapCity();
	map->loadMap("maps/moscow.png");
	map->loadMapObject("maps/moscow.xml");
	map->draw(scroller);
	
	
	//UI
	auto buildings = Buildings::create();
	buildings->setContentSize(Size(100,visibleSize.height));
	addChild(buildings);
	
	return true;
}
