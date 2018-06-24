#ifndef CAPITALISM_BUILDINGTYPEMANAGER_H
#define CAPITALISM_BUILDINGTYPEMANAGER_H

#include <string>
#include <unordered_map>
#include "Base/Manager.h"
#include "Model/Map/Building/TypeBuilding.h"

class BuildingTypeManager
{
public:
	static BuildingTypeManager* getInstance();
	
	const std::unordered_map<std::string, TypeBuilding*> &getTypesBuilding() const;
	TypeBuilding* getTypeBuilding(std::string &type);
	void addTypeBuilding(TypeBuilding* typeBuilding);

private:
	BuildingTypeManager();
	static BuildingTypeManager* buildingTypeManager;
	
	std::unordered_map<std::string, TypeBuilding*> typesBuilding;
};


#endif //CAPITALISM_BUILDINGTYPEMANAGER_H
