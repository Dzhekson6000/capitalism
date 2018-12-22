#ifndef CAPITALISM_LOADERHOUSEHOLD_H
#define CAPITALISM_LOADERHOUSEHOLD_H

#include "Base/Loader.h"
#include "Simulation/Managers/BuildingAManager.h"

class LoaderHousehold: public Loader
{
public:
	explicit LoaderHousehold(BuildingAManager* buildingAManager);
	
	bool load(const std::string &path) override;

private:
	BuildingAManager* buildingAManager;
};


#endif //CAPITALISM_LOADERHOUSEHOLD_H
