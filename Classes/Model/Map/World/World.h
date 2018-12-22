#ifndef CAPITALISM_WORLD_H
#define CAPITALISM_WORLD_H

#include "View/IsoScroller.h"
#include <Base/Loader.h>
#include <Manager/Map/LayerManager.h>
#include <Simulation/SimulationManager.h>
#include <Manager/Map/BuildingManager.h>
#include "Base/Manager.h"
#include "Model/Map/World/MapCity.h"

/**
 * класс который описывает отображаемый мир.
 */
class World:public IsoScroller, public Loader
{
public:
	CREATE_FUNC(World);
	
	/**
	 * вызывается для обновления мира
	 * @param dt дельта времени
	 */
	void update(float dt);
	
	void updateIsoPoints() override;
	
	BuildingManager* getBuildingManager() const;
	LayerManager* getLayerManager() const;
	
	/**
	 * загружает карту
	 * @param path путь к карте
	 * @return true - если успешно
	 */
	bool load(const std::string &path) override;
	
private:
	World();
	~World();
	bool init() override;
	
	SimulationManager* simulationManager;
	BuildingManager* buildingManager;
	LayerManager* layerManager;
	
	CC_SYNTHESIZE(MapCity*, _map, Map)

	void onMove() override;
	void onClickCell(const IsoPoint &point) override;
	
};


#endif //CAPITALISM_WORLD_H
