#include "Household.h"
#include "Simulation/SimulationManager.h"
#include "Market/Market.h"

Household::Household(Household::IncomeLevel incomeLevel):
		incomeLevel(incomeLevel),
		timer(0)
{
	setOwn(4,20);
}


void Household::update(float dt)
{
	timer+=dt;
	if(getPopulation()!=0)
	{
		CCLOG("Население:%d Денег:%f Еды:%f",
		      getPopulation(),
		      getOwn(3),
		      getOwn(4));
		work();
		eat();
		up();
	}
	
	Agent::update(dt);
}

void Household::work()
{
	//убираем старые заявки
	Market::Message messageClear;
	messageClear.type = Message::Type::ASK;
	messageClear.idOwn = 2;
	messageClear.price = 0;
	messageClear.sender = this;
	messageClear.date="clear";
	
	if(!((SimulationManager*)simulationManager)->getMarket()->message(messageClear))
	{
		CCLOG("Сообщение не обработно");
	}
	
	//создаём заявку
	setOwn(2,getPopulation());
	
	Market::Message message;
	message.type = Message::Type::ASK;
	message.idOwn = 2;
	message.price = 0;
	message.volume = getOwn(2);
	message.sender = this;
	
	if(!((SimulationManager*)simulationManager)->getMarket()->message(message))
	{
		CCLOG("Сообщение не обработно");
	}
}

void Household::eat()
{
	//убираем старые заявки
	Market::Message messageClear;
	messageClear.type = Message::Type::BID;
	messageClear.idOwn = 4;
	messageClear.price = 0;
	messageClear.sender = this;
	messageClear.date="clear";
	
	if(!((SimulationManager*)simulationManager)->getMarket()->message(messageClear))
	{
		CCLOG("Сообщение не обработно");
	}
	
	//создаём новые
	Market::Message message;
	message.type = Message::Type::BID;
	message.idOwn = 4;
	message.price = 0;
	message.volume = static_cast<float>(getPopulation()*1.5);
	message.sender = this;
	
	if(!((SimulationManager*)simulationManager)->getMarket()->message(message))
	{
		CCLOG("Сообщение не обработно");
	}
}

void Household::up()
{
	float satisfaction = getOwn(4)/getPopulation();
	if(satisfaction>1.3)
		satisfaction = 1.3;
	else if(satisfaction < 0.7)
		satisfaction = 0.7;

	setOwn(4,0);//всё сожрали
	setPopulation(static_cast<int>(getPopulation()*satisfaction));//расплодились или умерли
}

int Household::getPopulation() const
{
	return static_cast<int>(getOwn(1));
}

void Household::setPopulation(int population)
{
	setOwn(1,population);
}

float Household::getMoney() const
{
	return getOwn(3);
}

void Household::setMoney(float money)
{
	setOwn(3,money);
}
