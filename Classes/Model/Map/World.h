#ifndef CAPITALISM_WORLD_H
#define CAPITALISM_WORLD_H

#include "View/Scroller.h"
#include "Model/Map/MapCity.h"
#include "Model/Map/Cell.h"

/**
 * класс который хранит в себе всей тайлы ландшафта и объекты
 */
class World: public Scroller
{
private:
	World();
	~World();
	bool init();
	
	Layer* _landscape;
	Layer* _objects; ///< объекты(постройки) и деревья
public:
	CREATE_FUNC(World);
	
	/**
	 * загружает карту
	 * создаёт и добавляет тайлы в мир рисуя карту
	 * @param mapPath путь к картинки карты
	 */
	void loadMap(std::string mapPath);
	
	/**
	 * загружает объекты из файла
	 * @param path путь к xml файл файлу с объектами
	 */
	void loadMapObject(std::string path);
	
	/**
	 * добавление тайла ландшафта
	 * @param cell тайл который нужно добавить
	 */
	void addLandscapeTile(Cell* cell);
	
	/**
	 * добавление объекта
	 * @param object
	 */
	void addObject(MapObject* object);
	/**
	 * удаление объекта
	 * @param object
	 */
	void removeObject(MapObject* object);
	
	CC_SYNTHESIZE(MapCity*, _map, Map)
};


#endif //CAPITALISM_WORLD_H
