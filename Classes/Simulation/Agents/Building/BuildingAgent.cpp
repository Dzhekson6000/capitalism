#include "BuildingAgent.h"
#include "Simulation/SimulationManager.h"

BuildingAgent::BuildingAgent(Building* building):
		building(building),
		householdCluster(nullptr),
		timer(0),
		salary(1),
		sb(1),
		price(1)
{
	setOwn(3,1000);
}

BuildingAgent::~BuildingAgent()
{
	if(householdCluster)
	{
		delete householdCluster;
	}
}

bool BuildingAgent::init()
{
	CCLOG("Агент: %s", building->getNameSprite().c_str());
	
	TypeBuilding* typeBuilding = building->getTypeBuilding();
	if(typeBuilding->houseSpace!=0)
	{
		householdCluster = new Household::Cluster;
		householdCluster->high = new Household(Household::IncomeLevel::HIGH);
		householdCluster->middle = new Household(Household::IncomeLevel::MIDDLE);
		householdCluster->low = new Household(Household::IncomeLevel::LOW);
		((SimulationManager*)simulationManager)->getHouseholdManager()->addCluster(householdCluster);
	}
	
	return Agent::init();
}

Building* BuildingAgent::getBuilding() const
{
	return building;
}

Household::Cluster* BuildingAgent::getHouseholdCluster() const
{
	return householdCluster;
}

float BuildingAgent::getSalary() const
{
	return salary;
}

void BuildingAgent::setSalary(float salary)
{
	BuildingAgent::salary = salary;
}

void BuildingAgent::update(float dt)
{
	if(building->getTypeBuilding()->workSpace!=0)
	{
		CCLOG("Работало:%d Денег:%f Еды: %f ЗП: %f",
		      (int)getOwn(2),
		      getOwn(3),
		      getOwn(4),
		      salary
		);
		hiring();
		fabrication();
		sale();
	}
	
	Agent::update(dt);
}

void BuildingAgent::hiring()
{
	//убираем старые заявки
	Market::Message messageClear;
	messageClear.type = Message::Type::BID;
	messageClear.idOwn = 2;
	messageClear.price = 1;
	messageClear.sender = this;
	messageClear.date="clear";
	
	if(!((SimulationManager*)simulationManager)->getMarket()->message(messageClear))
	{
		CCLOG("Сообщение не обработно");
	}
	
	salary = ((SimulationManager*)simulationManager)->getMarket()->getPrice(2);
	if(salary==0)
		salary=1;
	if(getOwn(2)<building->getTypeBuilding()->workSpace)
		salary*=1+((1+rand()%5)*0.01);
	else if(getOwn(2)==building->getTypeBuilding()->workSpace)
		salary*=1-((1+rand()%5)*0.01);
	
	
	Market::Message message;
	message.type = Message::Type::BID;
	message.idOwn = 2;
	message.price = salary;
	message.volume = building->getTypeBuilding()->workSpace;
	message.sender = this;
	
	if(!((SimulationManager*)simulationManager)->getMarket()->message(message))
	{
		CCLOG("Сообщение не обработно");
	}
}

void BuildingAgent::fabrication()
{
	float countFab = getOwn(2)*1.2;
	sb=salary*0.8;
	
	setOwn(4, getOwn(4)+countFab);
	setOwn(2, 0);
}

void BuildingAgent::sale()
{
	//убираем старые заявки
	Market::Message messageClear;
	messageClear.type = Message::Type::ASK;
	messageClear.idOwn = 4;
	messageClear.price = 1;
	messageClear.sender = this;
	messageClear.date="clear";
	
	if(!((SimulationManager*)simulationManager)->getMarket()->message(messageClear))
	{
		CCLOG("Сообщение не обработно");
	}
	
	//формируем цену
	float price = ((SimulationManager*)simulationManager)->getMarket()->getPrice(4);
	if(price==0)
		price = 1;
	if(getOwn(4) == 0)
	{
		price*=1+(1+rand()%5)*0.01;
	}
	else if(getOwn(4)>0)
	{
		price*=1-(1+rand()%5)*0.01;
	}
	
	if(price<sb)
		price = sb;
	
	
	Market::Message message;
	message.type = Message::Type::ASK;
	message.idOwn = 4;
	message.price = price;
	message.volume = getOwn(4);
	message.sender = this;
	
	if(!((SimulationManager*)simulationManager)->getMarket()->message(message))
	{
		CCLOG("Сообщение не обработно");
	}
}
