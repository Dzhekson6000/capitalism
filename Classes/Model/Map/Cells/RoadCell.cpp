#include "RoadCell.h"
#include "Controller/TileImageManager.h"

RoadCell::RoadCell()
{
	
}

bool RoadCell::initTile()
{
	SpriteFrame* sf = TileImageManager::getInstance()->getFrame("tiles", getNameCellOfType(_type), getFrame());
	if( !sf )
	{
		return false;
	}
	
	return Sprite::initWithSpriteFrame(sf);
}

int RoadCell::getFrame()
{
	int ret = Cell::getFrame();
	
	switch(ret)
	{
		case 4:
		case 8:
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
		case 0:
		case 15:
			return 10;
	}
	return -1;
}
