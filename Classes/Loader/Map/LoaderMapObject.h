#ifndef CAPITALISM_LOADERMAPOBJECT_H
#define CAPITALISM_LOADERMAPOBJECT_H

#include "Base/Loader.h"
#include "Manager/Map/LayerManager.h"
#include "Manager/Map/BuildingManager.h"
#include "Model/Map/MapObject.h"

class LoaderMapObject: public Loader
{
public:
	LoaderMapObject(LayerManager* layerManager, BuildingManager* buildingManager);
	
	/**
	 * загружает объекты из файла
	 * @param path путь к xml файл файлу с объектами
	 * @return
	 */
	bool load(const std::string &path) override;

private:
	LayerManager* layerManager;
	BuildingManager* buildingManager;
	
};


#endif //CAPITALISM_LOADERMAPOBJECT_H
