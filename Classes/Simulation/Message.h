#ifndef CAPITALISM_MESSAGE_H
#define CAPITALISM_MESSAGE_H

#include <string>
#include <functional>

class Message
{
public:
	enum class Type{
		INFO,
		REQUEST,
		RESPONSE,
		BID,
		ASK
	};
	
	Type type;
	std::string date;

};


#endif //CAPITALISM_MESSAGE_H
