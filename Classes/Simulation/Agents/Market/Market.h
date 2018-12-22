#ifndef CAPITALISM_MARKET_H
#define CAPITALISM_MARKET_H

#include "Simulation/Agent.h"
#include <unordered_map>
#include <vector>

class Market:public Agent
{
public:
	class Message:public Agent::Message
	{
	public:
		float volume;
		
		/**
		 * 0 = незамедлительная продажа или покупка
		 */
		float price;
		
		/**
		 * Идентификатор продукта
		 * 1 = рабочая сила
		 */
		int idOwn;
	};
	
	bool message(Agent::Message& message) override;
	void update(float dt) override;
	
	float getPrice(int idOwn);

private:
	struct Stack
	{
		float price = 0;
		std::vector<Message> fast_asks; ///< быстрая продажа
		std::vector<Message> fast_bids; ///< быстрая покупка
		std::vector<Message> asks; ///< продажа
		std::vector<Message> bids; ///< покупка
	};
	std::unordered_map<int, Stack> stacks;
	
	Stack& getOwnStack(int id);
	
	/**
	 * передача собственности
	 * @param trader1 от кого
	 * @param trader2 к кому
	 * @param idOwn что
	 * @param volume сколько
	 */
	void transfer(Agent* trader1,Agent* trader2, int idOwn, float volume);
	
	bool checkOwn(Agent* agent, int idOwn, float volume);
};


#endif //CAPITALISM_MARKET_H
