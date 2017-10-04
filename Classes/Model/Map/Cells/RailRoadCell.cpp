#include "RailRoadCell.h"
#include "Tools/TileImageManager.h"

RailRoadCell::RailRoadCell()
{
	
}

bool RailRoadCell::initTile()
{
	int frame = getFrame();
	SpriteFrame* sf = TileImageManager::getInstance()->getFrame("tiles", getNameCellOfType(_type), frame);
	if( !sf )
	{
		return false;
	}
	
	if(frame >= 2 && frame <= 5)
	{
		addGround();
	}
	
	return Sprite::initWithSpriteFrame(sf);
}

void RailRoadCell::addGround()
{
	SpriteFrame* sf = TileImageManager::getInstance()->getFrame("tiles", "ground");
	if( !sf )
	{
		return;
	}
	
	cocos2d::Sprite* s = Sprite::createWithSpriteFrame(sf);
	s->setPositionNormalized(s->getAnchorPoint());
	addChild(s,-1);
}

int RailRoadCell::getFrame()
{
	int ret = Cell::getFrame();
	
	switch(ret)
	{
		case 12:
			return 0;
		case 1:
		case 2:
		case 3:
			return 1;
		case 6:
			return 2;
		case 5:
			return 3;
		case 9:
			return 4;
		case 10:
			return 5;
		case 14:
			return 6;
		case 7:
			return 7;
		case 13:
			return 8;
		case 11:
			return 9;
		case 15:
			return 10;
	}
	
	return -1;
}
