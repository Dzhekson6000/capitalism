#ifndef CAPITALISM_PARKCELL_H
#define CAPITALISM_PARKCELL_H

#include "Model/Cell.h"

class ParkCell: public Cell
{
public:
	bool initTile();
	CREATE_FUNC(ParkCell)

private:
	ParkCell();
	
	int getFrame();
};


#endif //CAPITALISM_PARKCELL_H
