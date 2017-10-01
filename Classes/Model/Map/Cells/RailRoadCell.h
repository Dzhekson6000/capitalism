#ifndef CAPITALISM_RAILROADCELL_H
#define CAPITALISM_RAILROADCELL_H

#include "Model/Map/Cell.h"

class RailRoadCell: public Cell
{
public:
	bool initTile();
	CREATE_FUNC(RailRoadCell)

private:
	RailRoadCell();
	
	int getFrame();
	void addGround();
};


#endif //CAPITALISM_RAILROADCELL_H
