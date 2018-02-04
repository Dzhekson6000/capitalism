#include "LoaderMapObject.h"

using namespace tinyxml2;

LoaderMapObject::LoaderMapObject(World* world):_world(world)
{
}

void LoaderMapObject::loadMapObjectFile(std::string path)
{
	XMLDocument doc;
	doc.LoadFile(FileUtils::getInstance()->fullPathForFilename(path).c_str());
	loadMapObjectFile(doc);
}

void LoaderMapObject::loadMapObjectFile(tinyxml2::XMLDocument &doc)
{
	XMLNode* root = doc.FirstChildElement("area")->FirstChildElement("objects");
	
	for( XMLElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if( strcmp(e->Value(), "house") == 0)
		{
			_world->addObject(createObjectOfXML(e));
		}
	}
}

MapObject* LoaderMapObject::createObjectOfXML(tinyxml2::XMLElement* object)
{
	MapObject* ret = MapObject::create();
	
	auto id = atoi(object->Attribute("id"));
	auto width = atoi(object->Attribute("w"));
	auto length = atoi(object->Attribute("l"));
	auto height = atoi(object->Attribute("h"));
	//ret->setIdTile(id);
	//ret->setWidthTile(width);
	//ret->setLengthTile(length);
	//ret->setHeightTile(height);
	
	std::string delimiter = ":";
	std::string img = object->Attribute("img");
	
	size_t pos = 0;
	if((pos = img.find(delimiter)) == std::string::npos)
	{
		return nullptr;
	}
	
	auto group = img.substr(0, pos);
	auto name = img.erase(0, pos + delimiter.length());
	ret->setGroupTile(group);
	ret->setNameTile(name);
	
	
	int x = atoi(object->Attribute("x"));
	int y = atoi(object->Attribute("y"));
	ret->setIsoPoint(IsoPoint(x,y));
	
	ret->initObject();
	return ret;
}
