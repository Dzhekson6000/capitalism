#include "GameScene.h"
#include "Model/MapCity.h"
#include "Model/Config.h"
#include "Tools/Scroller.h"

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
	
	Image* imgmap = new Image();
	imgmap->initWithImageFile("maps/moscow.png");
	
	MapCity* map = new MapCity();
	map->loadMap(imgmap);
	map->loadMapObject("maps/moscow.xml");
	
	Scroller* scroller = Scroller::create();
	this->addChild(scroller);
	map->draw(scroller);
	
	
	//scroller->setScale(2);
	//scroller->setScale(0.5);
	
	return true;
}
