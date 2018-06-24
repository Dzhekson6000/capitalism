#include "LoaderTypeBuildings.h"
#include "Manager/BuildingTypeManager.h"

using namespace tinyxml2;

LoaderTypeBuildings::LoaderTypeBuildings()
{}

bool LoaderTypeBuildings::load(const std::string &path)
{
	XMLDocument doc;
	doc.LoadFile(FileUtils::getInstance()->fullPathForFilename(path).c_str());
	loadOfXML(doc);
	
	return Loader::load(path);
}

void LoaderTypeBuildings::loadOfXML(tinyxml2::XMLDocument &types)
{
	XMLNode* root = types.FirstChildElement("buildings");
	
	for( XMLElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if( strcmp(e->Value(), "building") == 0 )
		{
			createTypeOfXML(e);
		}
	}
}

void LoaderTypeBuildings::createTypeOfXML(tinyxml2::XMLElement* type)
{
	TypeBuilding* typeBuilding = new TypeBuilding;
	
	typeBuilding->width = atoi(type->Attribute("w"));
	typeBuilding->height = atoi(type->Attribute("h"));
	typeBuilding->length = atoi(type->Attribute("l"));
	
	typeBuilding->group = type->Attribute("group");
	typeBuilding->name  = type->Attribute("name");
	
	BuildingTypeManager::getInstance()->addTypeBuilding(typeBuilding);
	
}
