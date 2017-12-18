#ifndef CAPITALISM_LOADERMAP_H
#define CAPITALISM_LOADERMAP_H

#include "cocos2d.h"
#include "Model/Map/World.h"

class LoaderMap
{
public:
	LoaderMap(World* world);
	~LoaderMap();
private:
	/**
	 * мир в который нужно загружать карту
	 */
	World* _world;
	
public:
	/**
	 * загружает карту
	 * @param mapImage картинка карты
	 */
	void loadMap(cocos2d::Image* mapImage);
	/**
	 * загружает карту
	 * @param mapPath путь к картинки карты
	 */
	void loadMap(std::string mapPath);
	
	/**
	 * создаёт и добавляет тайлы в мир рисуя карту
	 */
	void draw();
};


#endif //CAPITALISM_LOADERMAP_H
