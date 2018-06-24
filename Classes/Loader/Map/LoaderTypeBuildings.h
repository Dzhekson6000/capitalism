#ifndef CAPITALISM_LOADERTYPEBUILDINGS_H
#define CAPITALISM_LOADERTYPEBUILDINGS_H

#include <string>
#include "Base/Loader.h"
#include "tinyxml2/tinyxml2.h"
#include "Manager/Map/BuildingManager.h"

/**
 * Класс обёртка для загрузка типов построек
 */
class LoaderTypeBuildings: public Loader
{
public:
	LoaderTypeBuildings();
	bool load(const std::string &path) override;

private:
	
	void createTypeOfXML(tinyxml2::XMLElement* type);
	void loadOfXML(tinyxml2::XMLDocument& types);

};


#endif //CAPITALISM_LOADERTYPEBUILDINGS_H
