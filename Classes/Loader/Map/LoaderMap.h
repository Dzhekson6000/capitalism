#ifndef CAPITALISM_LOADERMAP_H
#define CAPITALISM_LOADERMAP_H

#include "cocos2d.h"
#include "Base/Loader.h"
#include "Manager/Map/LayerManager.h"
#include "Model/Map/World/MapCity.h"

/**
 * Загрузчик карты. Поучает World и png карту и добавляет на world соответствующие клетки
 */
class LoaderMap: public Loader
{
public:
	LoaderMap(LayerManager* layerManager, MapCity* map);
	~LoaderMap();
	
	/**
	 * загружает карту
	 * создаёт и добавляет тайлы в мир рисуя карту
	 * @param path путь к изображению карты
	 * @return
	 */
	bool load(const std::string &path) override;

private:
	LayerManager* layerManager;
	MapCity* map;
	
	/**
	 * загружает карту
	 * создаёт и добавляет тайлы в мир рисуя карту
	 * @param mapImage картинка карты
	 */
	void loadMap(cocos2d::Image* mapImage);
	
	
};


#endif //CAPITALISM_LOADERMAP_H
