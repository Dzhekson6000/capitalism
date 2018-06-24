#ifndef CAPITALISM_LOADERMAPOBJECT_H
#define CAPITALISM_LOADERMAPOBJECT_H

#include "tinyxml2/tinyxml2.h"
#include "Base/Loader.h"
#include <Manager/Map/LayerManager.h>
#include "Model/Map/MapObject.h"

class LoaderMapObject: public Loader
{
public:
	LoaderMapObject(LayerManager* layerManager);
	
	/**
	 * загружает объекты из файла
	 * @param path путь к xml файл файлу с объектами
	 * @return
	 */
	bool load(const std::string &path) override;

private:
	LayerManager* layerManager;
	
	/**
	 * загружает объекты из файла
	 * @param doc xml элемент файла
	 */
	void loadMapObjectFile(tinyxml2::XMLDocument& doc);
	
	/**
	 * Создаёт и возвращает объект из xml элемента объекта
	 * @param object xml элемента объекта
	 * @return созданный объект
	 */
	MapObject* createObjectOfXML(tinyxml2::XMLElement* object);
	
	
};


#endif //CAPITALISM_LOADERMAPOBJECT_H
