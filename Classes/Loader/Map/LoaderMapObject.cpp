#include "LoaderMapObject.h"
#include "tinyxml2/tinyxml2.h"
#include "Manager/BuildingTypeManager.h"

using namespace tinyxml2;

LoaderMapObject::LoaderMapObject(LayerManager* layerManager, BuildingManager* buildingManager):
		layerManager(layerManager),
		buildingManager(buildingManager)
{
}

/**
 * загружает объекты из файла
 * @param doc xml элемент файла
 */
Building* createObjectOfXML(tinyxml2::XMLElement* object)
{
	std::string img = object->Attribute("img");
	TypeBuilding* typeBuilding = BuildingTypeManager::getInstance()->getTypeBuilding(img);
	
	if( !typeBuilding )
	{
		return nullptr;
	}
	
	Building* ret = Building::create();
	ret->setId(atoi(object->Attribute("id")));
	ret->setTypeBuilding(typeBuilding);
	int x = atoi(object->Attribute("x"));
	int y = atoi(object->Attribute("y"));
	ret->setIsoPoint(IsoPoint(x, y));
	ret->initObject();
	
	return ret;
}

/**
 * Создаёт и возвращает объект из xml элемента объекта
 * @param object xml элемента объекта
 * @return созданный объект
 */
void loadMapObjectFile(BuildingManager* buildingManager, LayerManager* layerManager, tinyxml2::XMLDocument &doc)
{
	XMLNode* root = doc.FirstChildElement("area")->FirstChildElement("buildings");
	
	for( XMLElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if( strcmp(e->Value(), "build") == 0 )
		{
			Building* buildObject = createObjectOfXML(e);
			layerManager->addMapObject(buildObject);
			buildingManager->build(buildObject);
		}
	}
}

bool LoaderMapObject::load(const std::string &path)
{
	XMLDocument doc;
	doc.LoadFile(FileUtils::getInstance()->fullPathForFilename(path).c_str());
	loadMapObjectFile(buildingManager, layerManager, doc);
	
	return Loader::load(path);
}
