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
	
public:
	void loadMap(cocos2d::Image* map);
	void draw(cocos2d::Node* scene);
	
	unsigned char *getPixel(int x, int y);
	int getType(int x, int y);
};


#endif //CAPITALISM_MAP_H
