#ifndef CAPITALISM_LOADERCOMPANY_H
#define CAPITALISM_LOADERCOMPANY_H

#include "Base/Loader.h"
#include "tinyxml2/tinyxml2.h"
#include "Simulation/Managers/CompaniesManager.h"
#include "Simulation/Agents/Company.h"

class LoaderCompany: public Loader
{
public:
	LoaderCompany(CompaniesManager* simulationManager);
	~LoaderCompany();
	
	/**
	 * загружает компании на карте
	 * @param path путь к карте
	 * @return true - если успешно
	 */
	bool load(const std::string &path) override;

private:
	CompaniesManager* companiesManager;
	
	Company* createCompanyOfXML(tinyxml2::XMLElement* object);
};


#endif //CAPITALISM_LOADERCOMPANY_H
