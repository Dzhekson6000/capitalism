#ifndef CAPITALISM_IMAGEMANAGER_H
#define CAPITALISM_IMAGEMANAGER_H

#include <string>
#include <vector>
#include <unordered_map>
#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"

using namespace tinyxml2;

class ImageManager
{
public:
	static ImageManager* getInstance();
	
	struct SpriteItem
	{
		std::vector<cocos2d::SpriteFrame*> frames;
	};
	
	struct Group
	{
		std::unordered_map<std::string, SpriteItem*> sprites;
	};
	
	void parserSprites(XMLElement* sprites);
	
	cocos2d::SpriteFrame* getFrame(std::string group, std::string sprite, int frame = 0);
private:
	static ImageManager* _imageManager;
	
	ImageManager();
	~ImageManager();
	
	CC_SYNTHESIZE(std::string, _spritesRoot, SpritesRoot);
	
	std::unordered_map<std::string, Group*> _groups;
	
	void parserSprite(XMLElement* sprite, std::string& path, Group* group);
	bool parseCoords(std::string coords, cocos2d::Rect& rect, cocos2d::Vec2& vec);
	
	void releaseImage();
	
};


#endif //CAPITALISM_IMAGEMANAGER_H
