#ifndef CAPITALISM_MAP_H
#define CAPITALISM_MAP_H

#include "cocos2d.h"

class MapCity
{
public:
	MapCity();
	~MapCity();
private:
	cocos2d::Image *_map;
	int _widthMap;
	int _heightMap;
	int _countChenal;
	
	void releaseMap();
	
	cocos2d::Sprite* createSprite(std::string name);
	cocos2d::Sprite* getCell(int x, int y,unsigned char* pixel);
	unsigned char *getPixel(int x, int y);
public:
	void loadMap(cocos2d::Image* map);
	void draw(cocos2d::Layer* scene);
};


#endif //CAPITALISM_MAP_H
