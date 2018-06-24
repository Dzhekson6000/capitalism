#ifndef CAPITALISM_LOADERWORLD_H
#define CAPITALISM_LOADERWORLD_H

#include "Loader.h"
#include "Model/Map/World/World.h"

class LoaderWorld: public Loader
{
public:
	explicit LoaderWorld(World* world);
protected:
	World* world;///< мир в который нужно загружать
};


#endif //CAPITALISM_LOADERWORLD_H
