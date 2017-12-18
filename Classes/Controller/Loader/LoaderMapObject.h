#ifndef CAPITALISM_LOADERMAPOBJECT_H
#define CAPITALISM_LOADERMAPOBJECT_H

#include "tinyxml2/tinyxml2.h"
#include "Model/Map/World.h"
#include "Model/Map/MapObject.h"

class LoaderMapObject
{
public:
	LoaderMapObject(World* world);
public:
	/**
	 * загружает объекты из файла
	 * @param path путь к xml файл файлу с объектами
	 */
	void loadMapObjectFile(std::string path);
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

private:
	World* _world;
};


#endif //CAPITALISM_LOADERMAPOBJECT_H
