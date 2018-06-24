#include "LoaderMapObject.h"
#include "Model/Map/Building/Building.h"
#include "Manager/BuildingTypeManager.h"

using namespace tinyxml2;

LoaderMapObject::LoaderMapObject(LayerManager* layerManager):layerManager(layerManager)
{
}

bool LoaderMapObject::load(const std::string &path)
{
	XMLDocument doc;
	doc.LoadFile(FileUtils::getInstance()->fullPathForFilename(path).c_str());
	loadMapObjectFile(doc);
	
	return Loader::load(path);
}

void LoaderMapObject::loadMapObjectFile(tinyxml2::XMLDocument &doc)
{
	XMLNode* root = doc.FirstChildElement("area")->FirstChildElement("buildings");
	
	for( XMLElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if( strcmp(e->Value(), "build") == 0)
		{
			layerManager->addMapObject(createObjectOfXML(e));
		}
	}
}

MapObject* LoaderMapObject::createObjectOfXML(tinyxml2::XMLElement* object)
{
	std::string img = object->Attribute("img");
	TypeBuilding* typeBuilding = BuildingTypeManager::getInstance()->getTypeBuilding(img);
	
	if(!typeBuilding)
		return nullptr;
	
	Building* ret = Building::create();
	ret->setId(atoi(object->Attribute("id")));
	ret->setTypeBuilding(typeBuilding);
	int x = atoi(object->Attribute("x"));
	int y = atoi(object->Attribute("y"));
	ret->setIsoPoint(IsoPoint(x,y));
	ret->initObject();
	
	return ret;
}
