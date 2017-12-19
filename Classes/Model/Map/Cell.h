#ifndef CAPITALISM_CELL_H
#define CAPITALISM_CELL_H

#include <string>
#include <unordered_map>
#include "cocos2d.h"
#include "Model/IsoPoint.h"
#include "MapCity.h"

class Cell:public cocos2d::Sprite
{
public:
	/**
	 * @brief Инициализация
	 * @details загружает спрайт фрейм и инициализирует спрайт.
	 * @return
	 */
	virtual bool initTile();
	
	/**
	 * @brief устанавливает координаты положения
	 * @param isoPoint
	 */
	void setIsoPoint(const IsoPoint isoPoint);
	
	/**
	 * @brief возвращает имя по пикселю
	 * @param pixel
	 * @return
	 */
	static std::string getNameCellOfPixel(const unsigned char* pixel);
	/**
	 * @brief возвращает имя по номеру типа
	 * @param type
	 * @return
	 */
	static std::string getNameCellOfType(const int type);
private:
	/**
	 * @brief имя клетки
	 */
	static const std::unordered_map<int, std::string> _cellsName;
	
	/**
	 * @brief возвращает номер типо относительно положения этой клетки
	 * @param x
	 * @param y
	 * @return
	 */
	int getTypeOffset(int x, int y);
	
CC_SYNTHESIZE_READONLY(IsoPoint, _isoPoint, IsoPoint);
CC_SYNTHESIZE(int , _type, Type);
CC_SYNTHESIZE(MapCity*, _map, Map);

CREATE_FUNC(Cell)

protected:
	/**
	 * @return номер характерезующий его относительно соседних клеток
	 */
	virtual int getFrame();
	
	/**
	 * @brief проверяет соответствует ли клетка заданная относительно текущей её типу
	 * @param x
	 * @param y
	 * @return
	 */
	virtual bool checkSameType(int x, int y);
	Cell();
	
	/**
	 * @brief рисует текст на текущей клетке
	 * @param text
	 */
	void printDebugCell(std::string text);
};


#endif //CAPITALISM_CELL_H
