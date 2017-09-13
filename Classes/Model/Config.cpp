#include "Config.h"
#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"
#include "Tools/ImageManager.h"

USING_NS_CC;
using namespace tinyxml2;

Config::Config()
{
	
}

Config::~Config()
{
	
}

bool Config::loadConfigFile(const std::string &path)
{
	XMLDocument xml_doc;
	xml_doc.LoadFile(FileUtils::getInstance()->fullPathForFilename(path).c_str());
	
	XMLNode* root = xml_doc.FirstChildElement("config");
	
	for( XMLElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if( strcmp(e->Value(), "sprites_root") == 0)
		{
			ImageManager::getInstance()->setSpritesRoot(e->GetText());
		}
		else if( strcmp(e->Value(), "sprites") == 0)
		{
			ImageManager::getInstance()->parserSprites(e);
		}
	}
	
	
	return true;
}
