#ifndef CAPITALISM_CELL_H
#define CAPITALISM_CELL_H

#include "Model/Map/MapObject.h"
#include "Model/Map/World/MapCity.h"

class Cell:public MapObject
{
public:
	CREATE_FUNC(Cell)
	bool initObject() override;
	
private:
	
	/**
	 * @brief возвращает номер типа относительно положения этой клетки
	 * @param x
	 * @param y
	 * @return
	 */
	int getTypeOffset(int x, int y);
	
	CC_SYNTHESIZE(int , _type, TypeCell);
	CC_SYNTHESIZE(MapCity*, _map, Map);

protected:
	Cell();
	
	/**
	 * @return номер характерезующий его относительно соседних клеток
	 */
	int getBitMask();
	
	/**
	 * @brief проверяет соответствует ли клетка заданная относительно текущей её типу
	 * @param x
	 * @param y
	 * @return
	 */
	virtual bool checkSameType(int x, int y);
	
};


#endif //CAPITALISM_CELL_H
