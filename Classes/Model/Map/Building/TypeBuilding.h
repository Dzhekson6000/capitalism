#ifndef CAPITALISM_TYPEBUILDING_H
#define CAPITALISM_TYPEBUILDING_H

#include <string>

class TypeBuilding
{
public:
	int width;
	int height;
	int length;
	
	int houseSpace;
	int workSpace;
	
	std::string group;
	std::string name;
	
	TypeBuilding();
};


#endif //CAPITALISM_TYPEBUILDING_H
