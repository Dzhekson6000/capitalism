#include "LoaderConfig.h"
#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"
#include "Controller/TileImageManager.h"

USING_NS_CC;
using namespace tinyxml2;

bool LoaderConfig::loadConfigFile(const std::string &path)
{
	XMLDocument xml_doc;
	xml_doc.LoadFile(FileUtils::getInstance()->fullPathForFilename(path).c_str());
	
	XMLNode* root = xml_doc.FirstChildElement("config");
	
	for( XMLElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if( strcmp(e->Value(), "sprites_root") == 0)
		{
			TileImageManager::getInstance()->setSpritesRoot(e->GetText());
		}
		else if( strcmp(e->Value(), "sprites") == 0)
		{
			TileImageManager::getInstance()->parserSprites(e);
		}
	}
	
	
	return true;
}
