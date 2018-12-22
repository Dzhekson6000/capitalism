#include "HouseholdManager.h"

void HouseholdManager::addCluster(Household::Cluster* cluster)
{
	addNew(cluster->high);
	addNew(cluster->middle);
	addNew(cluster->low);
}
