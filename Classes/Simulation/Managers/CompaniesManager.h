#ifndef CAPITALISM_COMPANIESMANAGER_H
#define CAPITALISM_COMPANIESMANAGER_H

#include <vector>
#include "Simulation/Agents/Company.h"
#include "AgentsManager.h"

class CompaniesManager: public AgentsManager
{
public:
	CompaniesManager();
	~CompaniesManager();
	
	Company* getCompany(int id);
	
};


#endif //CAPITALISM_COMPANIESMANAGER_H
