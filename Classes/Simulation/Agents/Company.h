#ifndef CAPITALISM_COMPANY_H
#define CAPITALISM_COMPANY_H

#include "Simulation/Agent.h"

class Company: public Agent
{
public:
	enum class TypeOwner
	{
		NONE,
		PLAYER,
		COMPANY
	};
	
	Company();

protected:
	int id;
	float money;
	int owner;
	
	TypeOwner typeOwner;
	
public:
	int getId() const;
	void setId(int id);
	
	float getMoney() const;
	void setMoney(float money);
	
	int getOwner() const;
	void setOwner(int owner);
	
	TypeOwner getTypeOwner() const;
	void setTypeOwner(std::string typeOwner);
	
};


#endif //CAPITALISM_COMPANY_H
