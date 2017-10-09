#ifndef CAPITALISM_WORLD_H
#define CAPITALISM_WORLD_H

#include "View/Scroller.h"
#include "Model/Map/MapCity.h"
#include "Model/Map/Cell.h"

class World: public Scroller
{
private:
	World();
	bool init();
	
	Layer* _landscape;
public:
	CREATE_FUNC(World);
	void addLandscapeTile(Cell* cell);
	
	CC_SYNTHESIZE(MapCity*, _map, Map)
};


#endif //CAPITALISM_WORLD_H
