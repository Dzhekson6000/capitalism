#ifndef CAPITALISM_TYPES_H
#define CAPITALISM_TYPES_H

#include "cocos2d.h"

class Types
{
	//TODO: Нужно оптимизировать весь класс
public:
	static Types* getInstance();
	
private:
	Types();
	
	/*struct Group
	{
		std::unordered_map<std::string, SpriteItem*> sprites;
	};
	typedef std::unordered_map<std::string, Group*> GroupsType;
	
	CC_SYNTHESIZE_READONLY(GroupsType, _groups, Groups);
	*/
	
	
	
};


#endif //CAPITALISM_TYPES_H
