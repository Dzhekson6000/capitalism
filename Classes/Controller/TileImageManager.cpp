#include "TileImageManager.h"

USING_NS_CC;

TileImageManager* TileImageManager::_imageManager = nullptr;

TileImageManager* TileImageManager::getInstance()
{
	if (_imageManager == nullptr)
	{
		_imageManager = new TileImageManager();
	}
	return _imageManager;
}

TileImageManager::TileImageManager()
{
	
}

TileImageManager::~TileImageManager()
{
	releaseImage();
}

void TileImageManager::releaseImage()
{
	for(auto group: _groups)
	{
		for(auto sprite: group.second->sprites)
		{
			for(auto frame: sprite.second->frames)
			{
				frame->release();
			}
			delete sprite.second;
		}
		delete group.second;
	}
	_groups.clear();
}

void TileImageManager::parserSprites(XMLElement* sprites)
{
	std::string name = sprites->Attribute("name");
	std::string path = _spritesRoot + "/" + sprites->Attribute("image");
	
	Group* group = new Group();
	_groups.insert(std::make_pair(name, group));
	for( XMLElement* e = sprites->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		parserSprite(e, path, group);
	}
}

void TileImageManager::parserSprite(XMLElement* sprite, std::string& path, TileImageManager::Group* group)
{
	SpriteItem* spriteItem = new SpriteItem();
	std::string name = sprite->Attribute("name");
	
	
	if(sprite->Attribute("coords"))
	{
		std::string coords = sprite->Attribute("coords");
		Rect rect;
		Vec2 center;
		parseCoords(coords, rect,center);
		SpriteFrame* spriteFrame = SpriteFrame::create(path,rect);
		spriteFrame->setAnchorPoint(center);
		spriteItem->frames.push_back(spriteFrame);
	}
	else{
		
		for( XMLElement* e = sprite->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if(e->Attribute("coords"))
			{
				std::string coords = e->Attribute("coords");
				Rect rect;
				Vec2 center;
				parseCoords(coords, rect,center);
				SpriteFrame* spriteFrame = SpriteFrame::create(path,rect);
				spriteFrame->setAnchorPoint(center);
				spriteItem->frames.push_back(spriteFrame);
			}
			else if(e->Attribute("from")){
				int from = atoi(e->Attribute("from"));
				std::string flip;
				if(e->Attribute("flip"))
				{
					flip = e->Attribute("flip");
				}
				SpriteFrame* spriteFrame = spriteItem->frames.at(from-1)->clone();
				spriteFrame->setTexture(spriteItem->frames.at(from-1)->getTexture());
				spriteFrame->setAnchorPoint(spriteItem->frames.at(from-1)->getAnchorPoint());
				if(flip=="vert")
				{
					spriteFrame->setFlippedY(true);
				}
				else if(flip=="hor")
				{
					spriteFrame->setFlippedX(true);
				} else if(flip=="both")
				{
					spriteFrame->setFlippedX(true);
					spriteFrame->setFlippedY(true);
				}
				spriteItem->frames.push_back(spriteFrame);
			}
		}
	}
	
	group->sprites.insert(make_pair(name, spriteItem));
}

bool TileImageManager::parseCoords(std::string coords, cocos2d::Rect & rect, cocos2d::Vec2& vec)
{
	std::string s[6];
	std::string delimiter = ",";
	
	int i = 0;
	size_t pos = 0;
	std::string token;
	while ((pos = coords.find(delimiter)) != std::string::npos) {
		token = coords.substr(0, pos);
		s[i++]=token;
		coords.erase(0, pos + delimiter.length());
	}
	s[5] = coords;
	
	rect.setRect(
			atoi( s[0].c_str() ),
			atoi( s[1].c_str() ),
			atoi( s[2].c_str() ),
			atoi( s[3].c_str() )
	);
	
	vec.x = atoi( s[4].c_str() )/rect.size.width;
	vec.y = 1 - atoi( s[5].c_str() )/rect.size.height;
	
	return true;
}

cocos2d::SpriteFrame* TileImageManager::getFrame(std::string group, std::string sprite, int frame)
{
	auto g = _groups.find(group);
	if ( g == _groups.end() ) {
		CCLOG("sprite group %s not found", group.c_str());
		return nullptr;
	}
	
	auto s = g->second->sprites.find(sprite);
	if ( s == g->second->sprites.end() ) {
		CCLOG("sprite name %s of group %s not found", sprite.c_str(), group.c_str());
		return nullptr;
	}
	
	if(frame > s->second->frames.size()-1)
	{
		CCLOG("frame %d sprite name %s of group %s not found", frame, sprite.c_str(), group.c_str());
		return nullptr;
	}
	
	
	return s->second->frames.at(frame);
}
