#include "BuildingTypeManager.h"


BuildingTypeManager* BuildingTypeManager::buildingTypeManager = nullptr;

BuildingTypeManager* BuildingTypeManager::getInstance()
{
	if( buildingTypeManager == nullptr )
	{
		buildingTypeManager = new BuildingTypeManager();
	}
	return buildingTypeManager;
}

BuildingTypeManager::BuildingTypeManager()
{}

const std::unordered_map<std::string, TypeBuilding*> &BuildingTypeManager::getTypesBuilding() const
{
	return typesBuilding;
}

TypeBuilding* BuildingTypeManager::getTypeBuilding(std::string &type)
{
	auto find_entry = typesBuilding.find(type);
	if(find_entry!=typesBuilding.end())
	{
		return find_entry->second;
	}
	return nullptr;
}

void BuildingTypeManager::addTypeBuilding(TypeBuilding* typeBuilding)
{
	typesBuilding.emplace(std::pair<std::string,TypeBuilding*>(
			typeBuilding->group+":"+typeBuilding->name,
			typeBuilding
	));
}
