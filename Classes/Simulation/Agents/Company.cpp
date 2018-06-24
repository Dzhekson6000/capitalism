#include "Company.h"

Company::Company():
	typeOwner(TypeOwner::NONE),
	owner(0)
{}

int Company::getId() const
{
	return id;
}

void Company::setId(int id)
{
	Company::id = id;
}

float Company::getMoney() const
{
	return money;
}

void Company::setMoney(float money)
{
	Company::money = money;
}

int Company::getOwner() const
{
	return owner;
}

void Company::setOwner(int owner)
{
	Company::owner = owner;
}

Company::TypeOwner Company::getTypeOwner() const
{
	return typeOwner;
}

void Company::setTypeOwner(std::string typeOwner)
{
	if(typeOwner=="player")
	{
		Company::typeOwner = TypeOwner::PLAYER;
	}
	else if(typeOwner=="company")
	{
		Company::typeOwner = TypeOwner::COMPANY;
	}
}


