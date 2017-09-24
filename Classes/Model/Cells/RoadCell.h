#ifndef CAPITALISM_ROADCELL_H
#define CAPITALISM_ROADCELL_H

#include "Model/Cell.h"

class RoadCell: public Cell
{
public:
	bool initTile();
	CREATE_FUNC(RoadCell)

private:
	RoadCell();
	
	int getFrame();
};


#endif //CAPITALISM_ROADCELL_H
