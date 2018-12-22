#include "Market.h"
#include "cocos2d.h"

bool Market::message(Agent::Message &message)
{
	auto          &mmessage = (Message &)message;
	Market::Stack &stack    = getOwnStack(mmessage.idOwn);
	
	std::vector<Message>* list;
	if( mmessage.type == Message::Type::ASK )
	{
		if( mmessage.price == 0 )
		{
			list = &stack.fast_asks;
		}
		else
		{
			list = &stack.asks;
		}
	}
	else if( mmessage.type == Message::Type::BID )
	{
		if( mmessage.price == 0 )
		{
			list = &stack.fast_bids;
		}
		else
		{
			list = &stack.bids;
		}
		
	}
	
	if( mmessage.date == "clear" )
	{
		list->erase(
				std::remove_if(
						list->begin(),
						list->end(),
						[mmessage](const Message &mes)
						{
							return mes.sender == mmessage.sender;
						}),
				list->end());
		
	}
	else
	{
		list->push_back(mmessage);
	}
	
	return Agent::message(message);
}

void Market::update(float dt)
{
	auto sort_ascending = [](Message a, Message b) { return a.price < b.price; };
	
	for( auto& stack_i: stacks )
	{
		int           idOwn  = stack_i.first;
		Market::Stack &stack = stack_i.second;
		std::sort(stack.bids.begin(), stack.bids.end(), sort_ascending);
		std::sort(stack.asks.begin(), stack.asks.end(), sort_ascending);
		
		//покупаем по удовлетворительной цене
		while( stack.bids.size() != 0 && stack.asks.size() != 0 )
		{
			Message &bidMessage = stack.bids.back();
			Message &askMessage = stack.asks.back();
			
			bool isRemoveBid = false;
			bool isRemoveAsk = false;
			
			if( bidMessage.price >= askMessage.price )
			{
				float volume = askMessage.sender->getOwn(idOwn);
				
				if( volume <= askMessage.volume )
				{//если продавец имеет меньше чем в заявки
					volume      = askMessage.volume;
					isRemoveAsk = true;
				}
				
				if( volume >= bidMessage.volume )
				{//если покупателю нужно меньше
					volume      = bidMessage.volume;
					isRemoveBid = true;
				}
				
				float bidMoney = bidMessage.sender->getOwn(3);
				if( bidMoney < volume*askMessage.price )
				{//не хватает денег что бы всё купить
					volume      = bidMoney/askMessage.price;//покупаем столько на сколько хватает
					isRemoveBid = true;
				}
				
				//переводим деньги
				transfer(bidMessage.sender, askMessage.sender, 3, volume*askMessage.price);
				//переводим товар
				transfer(askMessage.sender, bidMessage.sender, idOwn, volume);
				
				stack.price = askMessage.price;
				
				bidMessage.volume -= volume;
				askMessage.volume -= volume;
			}
			else
			{
				break;//не можем купить т.к. цена продажи выше цены покупки.
			}
			
			if( isRemoveBid )
			{
				stack.bids.pop_back();
			}
			if( isRemoveAsk )
			{
				stack.asks.pop_back();
			}
			
		}
		
		//блиц покупка
		while( stack.fast_bids.size() != 0 && stack.asks.size() != 0 )
		{
			Message &bidMessage = stack.fast_bids.back();
			Message &askMessage = stack.asks.back();
			
			bool isRemoveBid = false;
			bool isRemoveAsk = false;
			
			float volume = askMessage.sender->getOwn(idOwn);
			
			if( askMessage.volume > volume )
			{//если продавец имеет меньше чем в заявки
				isRemoveAsk = true;
			}
			else
			{
				volume = askMessage.volume;
			}
			
			if( volume >= bidMessage.volume )
			{//если покупателю нужно меньше
				volume      = bidMessage.volume;
				isRemoveBid = true;
			}
			
			float bidMoney = bidMessage.sender->getOwn(3);
			if( bidMoney < volume*askMessage.price )
			{//не хватает денег что бы всё купить
				volume      = bidMoney/askMessage.price;//покупаем столько на сколько хватает
				isRemoveBid = true;
			}
			
			//переводим деньги
			transfer(bidMessage.sender, askMessage.sender, 3, volume*askMessage.price);
			//переводим товар
			transfer(askMessage.sender, bidMessage.sender, idOwn, volume);
			
			stack.price = askMessage.price;
			
			bidMessage.volume -= volume;
			askMessage.volume -= volume;
			
			if( isRemoveBid )
			{
				stack.fast_bids.pop_back();
			}
			if( isRemoveAsk || askMessage.volume == 0)
			{
				stack.asks.pop_back();
			}
		}
		
		//блиц продажа
		while( stack.bids.size() != 0 && stack.fast_asks.size() != 0 )
		{
			Message &bidMessage = stack.bids.back();
			Message &askMessage = stack.fast_asks.back();
			
			bool isRemoveBid = false;
			bool isRemoveAsk = false;
			
			float volume = askMessage.volume;
			
			if( volume > askMessage.sender->getOwn(idOwn) )
			{//если продавец имеет меньше чем в заявки
				isRemoveAsk = true;
				volume = askMessage.sender->getOwn(idOwn);
			}
			
			if( volume >= bidMessage.volume )
			{//если покупателю нужно меньше
				volume = bidMessage.volume;
			}
			
			float bidMoney = bidMessage.sender->getOwn(3);
			if( bidMoney < volume*bidMessage.price )
			{//не хватает денег что бы всё купить
				volume      = bidMoney/bidMessage.price;//покупаем столько на сколько хватает
				isRemoveBid = true;
			}
			
			//переводим деньги
			transfer(bidMessage.sender, askMessage.sender, 3, volume*bidMessage.price);
			//переводим товар
			transfer(askMessage.sender, bidMessage.sender, idOwn, volume);
			
			stack.price = bidMessage.price;
			
			bidMessage.volume -= volume;
			askMessage.volume -= volume;
			
			if( isRemoveBid || bidMessage.volume == 0 )
			{
				stack.bids.pop_back();
			}
			if( isRemoveAsk || askMessage.volume == 0 )
			{
				stack.fast_asks.pop_back();
			}
		}
	}
	Agent::update(dt);
}

float Market::getPrice(int idOwn)
{
	return getOwnStack(idOwn).price;
}

Market::Stack &Market::getOwnStack(int id)
{
	auto stack = stacks.find(id);
	if( stack == stacks.end())
	{
		stack = stacks.emplace(id, Stack()).first;
	}
	return stack->second;
}

void Market::transfer(Agent* trader1, Agent* trader2, int idOwn, float volume)
{
	trader1->setOwn(idOwn, trader1->getOwn(idOwn) - volume);
	trader2->setOwn(idOwn, trader2->getOwn(idOwn) + volume);
	
}


