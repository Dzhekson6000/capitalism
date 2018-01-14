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
	 * создаёт и добавляет тайлы в мир рисуя карту
	 * @param mapImage картинка карты
	 */
	void loadMap(cocos2d::Image* mapImage);
	/**
	 * загружает карту
	 * создаёт и добавляет тайлы в мир рисуя карту
	 * @param mapPath путь к картинки карты
	 */
	void loadMap(std::string mapPath);
	
};


#endif //CAPITALISM_LOADERMAP_H
