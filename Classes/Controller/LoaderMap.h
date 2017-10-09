#ifndef CAPITALISM_LOADERMAP_H
#define CAPITALISM_LOADERMAP_H

#include "cocos2d.h"
#include <vector>
#include "Model/Map/World.h"

class LoaderMap
{
public:
	LoaderMap(World* world);
	~LoaderMap();
private:
	World* _world;
	
public:
	void loadMap(cocos2d::Image* mapImage);
	void loadMap(std::string mapPath);
	void loadMapObject(std::string path);
	void draw();
};


#endif //CAPITALISM_LOADERMAP_H
