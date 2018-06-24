#ifndef CAPITALISM_MESSAGE_H
#define CAPITALISM_MESSAGE_H

#include <string>

class Message
{
public:
	enum class Type{
		INFO,
		REQUEST,
		RESPONSE
	};
	
	Type type;
	std::string date;

};


#endif //CAPITALISM_MESSAGE_H
