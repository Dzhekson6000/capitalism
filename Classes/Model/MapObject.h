#ifndef CAPITALISM_MAPOBJECT_H
#define CAPITALISM_MAPOBJECT_H

#include "Model/IsoPoint.h"
#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"

USING_NS_CC;

class MapObject:public Sprite
{
public:
	int _id;
	int _width;
	int _length;
	int _height;
	
	std::string _group;
	std::string _name;
	
	void parserObject(tinyxml2::XMLElement* object);
	virtual bool initObject();
	
	void setIsoPoint(const IsoPoint isoPoint);
CC_SYNTHESIZE_READONLY(IsoPoint, _isoPoint, IsoPoint);
	
	CREATE_FUNC(MapObject)
protected:
	MapObject();
};


#endif //CAPITALISM_MAPOBJECT_H
