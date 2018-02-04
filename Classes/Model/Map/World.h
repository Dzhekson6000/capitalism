#ifndef CAPITALISM_WORLD_H
#define CAPITALISM_WORLD_H

#include "View/Scroller.h"
#include "Model/Map/MapCity.h"
#include "GroupObject.h"

/**
 * класс который описывает отображаемый мир.
 */
class World: public Scroller
{
private:
	World();
	~World();
	bool init();
	
	GroupObject* _objects; ///<  объекты(тайлы, постройки и деревья)
	
protected:
	void onMove() override;
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
	void addLandscapeTile(MapObject* cell);
	
	GroupObject* getObjects();
	
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
