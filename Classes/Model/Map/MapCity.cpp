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
}

unsigned char* MapCity::getPixel(int x, int y)
{
	return _map->getData() + (x + y*((int)_size.width))*_countChenal;
}

int MapCity::getType(int x, int y)
{
	int type = *(getPixel(x, y)+2);
	if(type==132) type = 4;//TODO: временный хак что бы не рисовать парковки
	return type;
}

Size MapCity::getSize() const
{
	return _size;
}

void MapCity::setSize(const Size &size)
{
	_size = size;
}
