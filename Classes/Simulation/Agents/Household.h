#ifndef CAPITALISM_HOUSEHOLD_H
#define CAPITALISM_HOUSEHOLD_H

#include "Simulation/Agent.h"
#include "cocos2d.h"

/**
 * Агент домохозяйств
 */
class Household:public Agent
{
public:
	/**
	 * уровень дохода
	 */
	enum class IncomeLevel
	{
		HIGH, ///<высокий
		MIDDLE, ///<средний
		LOW ///<низкий
	};
	
	struct Cluster
	{
		Household* high;
		Household* middle;
		Household* low;
	};
	
	explicit Household(IncomeLevel incomeLevel);
	
	void update(float dt) override;
	
	int getPopulation() const;
	void setPopulation(int population);
	float getMoney() const;
	void setMoney(float money);
	
private:
	IncomeLevel incomeLevel;
	
	cocos2d::Point position;///< позиция в клетках

private:
	float timer;
	
	void work();///< работаем
	void eat();///< тратим деньги
	void up();///< ростём
};


#endif //CAPITALISM_HOUSEHOLD_H
