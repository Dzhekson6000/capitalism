#ifndef CAPITALISM_MAPCITY_H
#define CAPITALISM_MAPCITY_H

#include "cocos2d.h"
#include "MapObject.h"

/**
 * Класс города. Хранит в себе карту города.
 */
class MapCity
{
private:
	CC_SYNTHESIZE(int, _widthMap,Width);
	CC_SYNTHESIZE(int, _heightMap, Height);
	CC_SYNTHESIZE(int, _countChenal, CountChenal);
	
	CC_SYNTHESIZE(cocos2d::Image*, _map, Landscape);
public:
	MapCity();
	~MapCity();
	
	/**
	 * выгрузка карты и объектов
	 */
	void release();
	
	
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
