#include "MapCity.h"

MapCity::MapCity():
	_map(nullptr)
{
	
}

MapCity::~MapCity()
{
	release();
}

void MapCity::release()
{
	if( _map )
	{
		delete _map;
		_map = nullptr;
	}
	
	for(auto obj: _mapObjects)
	{
		delete obj;
	}
}

void MapCity::addObject(MapObject* object)
{
	_mapObjects.push_back(object);
}

void MapCity::removeObject(MapObject* object)
{
	for( auto iter = _mapObjects.begin(); iter != _mapObjects.end(); ++iter )
	{
		if( *iter == object )
		{
			_mapObjects.erase( iter );
			break;
		}
	}
}

unsigned char* MapCity::getPixel(int x, int y)
{
	return _map->getData() + (x + y*_widthMap)*_countChenal;
}

int MapCity::getType(int x, int y)
{
	int type = *(getPixel(x, y)+2);
	if(type==132) type = 4;//TODO: временный хак что бы не рисовать парковки
	return type;
}
