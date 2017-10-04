#include "MapObject.h"
#include "Tools/TileImageManager.h"

MapObject::MapObject()
{
	
}

void MapObject::parserObject(tinyxml2::XMLElement* object)
{
	_id = atoi(object->Attribute("id"));
	_width = atoi(object->Attribute("w"));
	_length = atoi(object->Attribute("l"));
	_height = atoi(object->Attribute("h"));
	
	int x = atoi(object->Attribute("x"))-_length;
	int y = atoi(object->Attribute("y"))-_width;
	
	setIsoPoint(IsoPoint(x+1,y+1));
	
	std::string delimiter = ":";
	std::string img = object->Attribute("img");
	
	size_t pos = 0;
	if((pos = img.find(delimiter)) == std::string::npos)
	{
		return;
	}
	
	_group = img.substr(0, pos);
	_name = img.erase(0, pos + delimiter.length());
}

bool MapObject::initObject()
{
	SpriteFrame* sf = TileImageManager::getInstance()->getFrame(_group, _name, 1);
	if( !sf )
	{
		return false;
	}
	
	return Sprite::initWithSpriteFrame(sf);
}

void MapObject::setIsoPoint(const IsoPoint isoPoint)
{
	_isoPoint = isoPoint;
	setPosition(Vec2(_isoPoint.getX(), _isoPoint.getY()));
}
