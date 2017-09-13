#include "MapCity.h"
#include "IsoPoint.h"
#include "Tools/ImageManager.h"

USING_NS_CC;

MapCity::MapCity():
		_widthMap(300),
		_heightMap(300),
		_map(nullptr)
{
}

MapCity::~MapCity()
{
	releaseMap();
}

void MapCity::releaseMap()
{
	if( _map )
	{
		delete _map;
		_map = nullptr;
	}
}

void MapCity::loadMap(cocos2d::Image* map)
{
	releaseMap();
	_widthMap  = map->getWidth();
	_heightMap = map->getHeight();
	
	_countChenal = 3;
	if( map->hasAlpha())
	{
		_countChenal = 4;
	}
	
	_map = map;
	
}

cocos2d::Sprite* MapCity::createSprite(std::string name)
{
	SpriteFrame* sf = ImageManager::getInstance()->getFrame("tiles", name);
	if( !sf )
	{
		return nullptr;
	}
	return Sprite::createWithSpriteFrame(sf);
	
}

cocos2d::Sprite* MapCity::getCell(int x, int y, unsigned char* pixel)
{
	cocos2d::Sprite* ret = nullptr;
	int type = *(pixel + 2);
	switch( type )
	{
		case 0:
			ret = createSprite("ground");
			break;
		case 1:
			ret = createSprite("tundra");
			break;
		case 2:
			ret = createSprite("dryground");
			break;
		case 4:
			ret = createSprite("road");
			break;
		case 8:
			ret = createSprite("railroad");
			break;
		case 12:
			ret = createSprite("crossage");
			break;
		case 128:
			ret = createSprite("grass");
			break;
		case 129:
			ret = createSprite("desert");
			break;
		case 130:
			ret = createSprite("plage");
			break;
		case 131:
			ret = createSprite("city");
			break;
		case 132:
			ret = createSprite("court");
			break;
		case 133:
			ret = createSprite("park");
			break;
		case 134:
			ret = createSprite("asphault");
			break;
		case 135:
			ret = createSprite("square");
			break;
		case 136:
			ret = createSprite("industrial");
			break;
		case 255:
			ret = createSprite("water");
			break;
		
		case 36:
			ret = createSprite("ground");
			cocos2d::Sprite* s = createSprite("tree");
			s->setPositionNormalized(ret->getAnchorPoint());
			ret->addChild(s);
			break;
	}
	
	if( !ret )
	{
		CCLOG("Not found tiles: %d", type);
		return nullptr;
	}
	
	IsoPoint point(x, y);
	ret->setPosition(Vec2(point.getX(), point.getY()));
	
	return ret;
}

void MapCity::draw(cocos2d::Layer* scene)
{
	for( int i = _widthMap-1; i >= 0; i-- )
	{
		for( int j = _heightMap-1; j >= 0; j-- )
		{
			Sprite* sprite = getCell(i, j-120, getPixel(i, j));
			if( sprite )
			{
				scene->addChild(sprite, 0);
			}
		}
	}
}

unsigned char* MapCity::getPixel(int x, int y)
{
	return _map->getData() + (x + y*_widthMap)*_countChenal;
}
