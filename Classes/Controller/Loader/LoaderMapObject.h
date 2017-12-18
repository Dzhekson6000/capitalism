#ifndef CAPITALISM_LOADERMAPOBJECT_H
#define CAPITALISM_LOADERMAPOBJECT_H

#include "tinyxml2/tinyxml2.h"
#include "Model/Map/World.h"
#include "Model/Map/MapObject.h"

class LoaderMapObject
{
public:
	LoaderMapObject(World* world);
public:
	void loadMapObjectFile(std::string path);
	void loadMapObjectFile(tinyxml2::XMLDocument& doc);
	MapObject* createObjectOfXML(tinyxml2::XMLElement* object);

private:
	World* _world;
};


#endif //CAPITALISM_LOADERMAPOBJECT_H
