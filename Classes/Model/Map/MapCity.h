#ifndef CAPITALISM_MAPCITY_H
#define CAPITALISM_MAPCITY_H

#include "cocos2d.h"
#include "MapObject.h"

class MapCity
{
private:
	CC_SYNTHESIZE(int, _widthMap,Width);
	CC_SYNTHESIZE(int, _heightMap, Height);
	CC_SYNTHESIZE(int, _countChenal, CountChenal);
	
	CC_SYNTHESIZE_READONLY(std::vector<MapObject*>, _mapObjects, MapObject);
	
	CC_SYNTHESIZE(cocos2d::Image*, _map, Landscape);
public:
	MapCity();
	~MapCity();
	
	/**
	 * выгрузка карты и объектов
	 */
	void release();
	
	/**
	 * добавление объекта
	 * @param object
	 */
	void addObject(MapObject* object);
	/**
	 * удаление объекта
	 * @param object
	 */
	void removeObject(MapObject* object);
	
	
	unsigned char *getPixel(int x, int y);
	/**
	 * получение номера типа тайла
	 * @param x
	 * @param y
	 * @return номер тайла
	 */
	int getType(int x, int y);

};


#endif //CAPITALISM_MAPCITY_H
