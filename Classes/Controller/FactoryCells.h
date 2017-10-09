#ifndef CAPITALISM_FACTORYCELLS_H
#define CAPITALISM_FACTORYCELLS_H

#include "Model/Map/Cell.h"

class FactoryCells
{
public:
	static FactoryCells* getInstance();
	
	Cell* createCell(MapCity* map, IsoPoint point, int type);
private:
	
	static FactoryCells* _factoryCells;
	FactoryCells();
	~FactoryCells();
	
	void addTreeCell(Cell* cell);
	Cell* createCellOfType(int type);
};


#endif //CAPITALISM_FACTORYCELLS_H
