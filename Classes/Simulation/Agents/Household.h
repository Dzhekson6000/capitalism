#ifndef CAPITALISM_HOUSEHOLD_H
#define CAPITALISM_HOUSEHOLD_H

#include "Simulation/Agent.h"
#include "cocos2d.h"

/**
 * Агент домохозяйств
 */
class Household: public Agent
{
private:
	/**
	 * уровень дохода
	 */
	enum class IncomeLevel
	{
		high, ///<высокий
		middle, ///<средний
		low ///<низкий
	};

	IncomeLevel _incomeLevel;
	int _population;
	float _workforce;///< трудовые ресурсы
	float _money;///< финансы домохозяства
	
	cocos2d::Point _postition;
};


#endif //CAPITALISM_HOUSEHOLD_H
