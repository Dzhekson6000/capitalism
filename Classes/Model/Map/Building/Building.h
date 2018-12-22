#ifndef CAPITALISM_BUILDING_H
#define CAPITALISM_BUILDING_H

#include "cocos2d.h"
#include "Model/Map/MapObject.h"
#include "TypeBuilding.h"

class Building:public MapObject
{
public:
	CREATE_FUNC(Building)
	
	TypeBuilding* getTypeBuilding() const;
	void setTypeBuilding(TypeBuilding* typeBuilding);
	
	
	int getId() const;
	void setId(int id);
protected:
	int id;
	TypeBuilding* _typeBuilding;
	
	int getFrame() override;
};


#endif //CAPITALISM_BUILDING_H
