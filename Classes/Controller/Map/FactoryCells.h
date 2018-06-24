#ifndef CAPITALISM_FACTORYCELLS_H
#define CAPITALISM_FACTORYCELLS_H

#include "Model/Map/Cell/Cell.h"

class FactoryCells
{
public:
	static FactoryCells* getInstance();
	
	/**
	 * Создаёт клетку с сылкой на карту но не добавляет её. Нужно добавить потом.
	 * @param map карта к которой относится эта клетка(нужна для внутренней работы)
	 * @param point позиция клетки
	 * @param type номер типа клетки
	 * @return
	 */
	Cell* createCell(MapCity* map, IsoPoint point, int type);
private:
	
	static FactoryCells* _factoryCells;
	FactoryCells();
	~FactoryCells();
	
	/**
	 * Добавляет деревья на клетку
	 * @param cell клетка на которую нужно добавить деревья
	 */
	void addTreeCell(Cell* cell);
	/**
	 * Возвращает клетку согласно типу
	 * @param type номер типа
	 * @return указатель на клетку
	 */
	Cell* createCellOfType(int type);
};


#endif //CAPITALISM_FACTORYCELLS_H
