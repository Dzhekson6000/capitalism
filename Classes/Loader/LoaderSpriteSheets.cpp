#include "LoaderSpriteSheets.h"
#include <tinyxml2/tinyxml2.h>
#include "cocos2d.h"

USING_NS_CC;

std::string GetOnlyFileName(const std::string& path)
{
	std::string name(path);
	
	if(name.empty())
		return name;
	
	if(name[name.length() - 1] == '\\' || name[name.length() - 1] == '/')
		name.erase(name.length() - 1);
	
	size_t pos = name.find_last_of("\\/");
	
	if(pos != std::string::npos)
		name.erase(0, pos + 1);
	
	pos = name.find_last_of(".");
	
	if(pos != std::string::npos)
		name.erase(pos);
	
	return name;
}

LoaderSpriteSheets *const LoaderSpriteSheets::GetInstance() noexcept
{
    static LoaderSpriteSheets instance;
    return &instance;
}

LoaderSpriteSheets::LoaderSpriteSheets():
		dir_frames("ui/SpriteSheet/"),
        xml_format(".xml")
{
    FileUtils* fileUtils = FileUtils::getInstance();
    std::vector<std::string> filesFromDir = fileUtils->listFiles(dir_frames);
	images = cocos2d::SpriteFrameCache::getInstance();
    
    for(auto file : filesFromDir)
        if(fileUtils->getFileExtension(file) == xml_format)
            _loadImage(file);
}

LoaderSpriteSheets::~LoaderSpriteSheets() noexcept
{
    /*for (auto &[key, value] : images)
    {
        value->release();
    }*/
}

void LoaderSpriteSheets::_loadImage(const std::string &file_name)
{
	std::string file_path(dir_frames);
	file_path.append(GetOnlyFileName(file_name)).append(".png");
	
    tinyxml2::XMLDocument document;
    if (document.LoadFile(file_name.c_str()))
    {
        return;
    }

    if (auto const texture_atlas = document.FirstChild())
    {
	    for(tinyxml2::XMLElement* element = texture_atlas->FirstChildElement(); element != NULL; element = element->NextSiblingElement())
	    {
		    std::string name = element->Attribute("name");
		    int x = element->IntAttribute("x");
		    int y = element->IntAttribute("y");
		    int width = element->IntAttribute("width");
		    int height = element->IntAttribute("height");
		
		    images->addSpriteFrame(cocos2d::SpriteFrame::create(file_path, cocos2d::Rect(x, y, width, height)), name);
		   }
    }
}
