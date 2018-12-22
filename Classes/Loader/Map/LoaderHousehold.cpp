#include "LoaderHousehold.h"
#include "tinyxml2/tinyxml2.h"

using namespace tinyxml2;

LoaderHousehold::LoaderHousehold(BuildingAManager* buildingAManager):
		buildingAManager(buildingAManager)
{
}

void loadHouseholdFile(BuildingAManager* buildingAManager, tinyxml2::XMLDocument &doc)
{
	XMLNode* root = doc.FirstChildElement("area")->FirstChildElement("households");
	
	for( XMLElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if( strcmp(e->Value(), "building") == 0 )
		{
			const char* id = e->Attribute("id", nullptr);
			if( id )
			{
				BuildingAgent* buildingAgent = buildingAManager->getBuildingAgent(atoi(id));
				
				for( XMLElement* household = e->FirstChildElement();
				     household != NULL;
				     household = household->NextSiblingElement()
						)
				{
					Household* householdAgent = nullptr;
					std::string income = household->Attribute("income");
					if( income == "low" )
					{
						householdAgent = buildingAgent->getHouseholdCluster()->low;
					}
					else if( income == "middle" )
					{
						householdAgent = buildingAgent->getHouseholdCluster()->middle;
					}
					else if( income == "high" )
					{
						householdAgent = buildingAgent->getHouseholdCluster()->high;
					}
					
					if( householdAgent )
					{
						householdAgent->setMoney(atoi(household->Attribute("money")));
						householdAgent->setPopulation(atoi(household->Attribute("population")));
					}
					
				}
				
			}
		}
	}
}

bool LoaderHousehold::load(const std::string &path)
{
	XMLDocument doc;
	doc.LoadFile(FileUtils::getInstance()->fullPathForFilename(path).c_str());
	loadHouseholdFile(buildingAManager, doc);
	
	
	return Loader::load(path);
}
