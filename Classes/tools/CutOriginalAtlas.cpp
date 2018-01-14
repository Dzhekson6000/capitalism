#include "CutOriginalAtlas.h"

USING_NS_CC;

void CutOriginalAtlas::cutFromConfig(const std::string &pathConfigFile)
{
	std::string spritesRoot;
	XMLDocument xml_doc;
	xml_doc.LoadFile(FileUtils::getInstance()->fullPathForFilename(pathConfigFile).c_str());
	
	FileUtils::getInstance()->createDirectory(FileUtils::getInstance()->getDefaultResourceRootPath() + "tiles/");
	
	XMLNode* root = xml_doc.FirstChildElement("config");
	
	for( XMLElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if( strcmp(e->Value(), "sprites_root") == 0 )
		{
			spritesRoot = e->GetText();
		}
		else if( strcmp(e->Value(), "sprites") == 0 )
		{
			parserSprites(e, spritesRoot);
		}
	}
}

void CutOriginalAtlas::parserSprites(XMLElement* sprites, std::string spritesRoot)
{
	std::string nameGroup = sprites->Attribute("name");
	std::string path      = spritesRoot + "/" + sprites->Attribute("image");
	
	std::string pathDir = FileUtils::getInstance()->getDefaultResourceRootPath() + "tiles/" + nameGroup;
	if( !FileUtils::getInstance()->isDirectoryExist(pathDir))
	{
		FileUtils::getInstance()->createDirectory(pathDir);
	}
	
	for( XMLElement* e = sprites->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		parserSprite(e, path, nameGroup);
	}
}

void CutOriginalAtlas::parserSprite(XMLElement* sprite, std::string path, std::string nameGroup)
{
	std::string nameSprite = sprite->Attribute("name");
	
	std::string pathDir = FileUtils::getInstance()->getDefaultResourceRootPath() + "tiles/" + nameGroup + "/";
	
	if( sprite->Attribute("coords"))
	{
		std::string coords = sprite->Attribute("coords");
		Rect        rect;
		Vec2        center;
		parseCoords(coords, rect, center);
		SpriteFrame* spriteFrame = SpriteFrame::create(path, rect);
		spriteFrame->setAnchorPoint(center);
		saveSprite(pathDir + nameSprite + ".png", spriteFrame);
	}
	else
	{
		pathDir += nameSprite + "/";
		FileUtils::getInstance()->createDirectory(pathDir);
		
		for( XMLElement* e = sprite->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if( e->Attribute("coords"))
			{
				std::string coords = e->Attribute("coords");
				Rect        rect;
				Vec2        center;
				parseCoords(coords, rect, center);
				SpriteFrame* spriteFrame = SpriteFrame::create(path, rect);
				spriteFrame->setAnchorPoint(center);
				saveSprite(pathDir + e->Attribute("number") + ".png", spriteFrame);
			}
		}
	}
}

bool CutOriginalAtlas::parseCoords(std::string coords, cocos2d::Rect &rect, cocos2d::Vec2 &vec)
{
	std::string s[6];
	std::string delimiter = ",";
	
	int         i   = 0;
	size_t      pos = 0;
	std::string token;
	while((pos = coords.find(delimiter)) != std::string::npos )
	{
		token = coords.substr(0, pos);
		s[i++] = token;
		coords.erase(0, pos + delimiter.length());
	}
	s[5]       = coords;
	
	rect.setRect(
			atoi(s[0].c_str()),
			atoi(s[1].c_str()),
			atoi(s[2].c_str()),
			atoi(s[3].c_str())
	);
	
	vec.x = atoi(s[4].c_str())/rect.size.width;
	vec.y = 1 - atoi(s[5].c_str())/rect.size.height;
	
	return true;
}

void CutOriginalAtlas::saveSprite(const std::string &path, cocos2d::SpriteFrame* sf)
{
	Sprite       * sprite        = Sprite::createWithSpriteFrame(sf);
	Director::getInstance()->getRunningScene()->addChild(sprite);
	
	Director::getInstance()->getRenderer()->render();
	RenderTexture* renderTexture = RenderTexture::create(
			sprite->getContentSize().width,
			sprite->getContentSize().height,
			Texture2D::PixelFormat::RGBA8888);
	renderTexture->beginWithClear(0, 0, 0, 0);
	sprite->setAnchorPoint(Vec2(0, 0));
	sprite->setBlendFunc({GL_ONE, GL_ZERO});//TODO::из-за смешования текстур образуется артефакт на краях
	sprite->visit();
	renderTexture->end();
	
	Director::getInstance()->getRenderer()->render();
	Image* img = renderTexture->newImage();
	img->saveToFile(path,false);
	img->release();
	Director::getInstance()->getRunningScene()->removeChild(sprite);
	
	
}
