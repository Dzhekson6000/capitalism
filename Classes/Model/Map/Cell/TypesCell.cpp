#include "TypesCell.h"
#include "cocos2d.h"

//TODO:: нужно перенести это в конфиг файл и загружать все именна из конфига
const std::unordered_map<int, std::string> TypesCell::_cellsName
		                                           {
				                                           { 0,"ground"},
				                                           { 1,"tundra"},
				                                           { 2,"dryground"},
				                                           { 4, "road"},
				                                           { 8,"railroad"},
				                                           { 12,"crossage"},
				                                           { 128,"grass"},
				                                           { 129,"desert"},
				                                           { 130,"plage"},
				                                           { 131,"city"},
				                                           { 132,"court"},
				                                           { 133,"park"},
				                                           { 134,"asphault"},
				                                           { 135,"square"},
				                                           { 136,"industrial"},
				                                           { 255,"water"},
				                                           { 36,"tree"}
		                                           };

std::string TypesCell::getNameCellOfType(const int type)
{
	auto name = _cellsName.find(type);
	if(name == _cellsName.end())
	{
		CCLOG("Cell name id %d not found", type);
		return "";
	}
	return name->second;
}

std::string TypesCell::getNameCellOfPixel(const unsigned char* pixel)
{
	return TypesCell::getNameCellOfType(*(pixel + 2));
}
