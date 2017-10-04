#include "ParkCell.h"
#include "Tools/TileImageManager.h"

ParkCell::ParkCell()
{
	
}

bool ParkCell::initTile()
{
	int frame = getFrame();
	SpriteFrame* sf = TileImageManager::getInstance()->getFrame("tiles", getNameCellOfType(_type), frame);
	if( !sf )
	{
		return false;
	}
	
	return Sprite::initWithSpriteFrame(sf);
}

int ParkCell::getFrame()
{
	int ret = Cell::getFrame();
	
	switch(ret)
	{
		case 4:
		case 8:
		case 12:
			return 2;
		case 1:
		case 2:
		case 3:
			return 3;
		case 14:
			return 8;
		case 7:
			return 9;
		case 13:
			return 10;
		case 11:
			return 11;
		case 6:
			return 12;
		case 5:
			return 13;
		case 9:
			return 14;
		case 10:
			return 15;
		case 0:
		case 15:
			return 16;

	}
	
	return -1;
}
