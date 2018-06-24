#ifndef CAPITALISM_BUILDING_H
#define CAPITALISM_BUILDING_H

#include "cocos2d.h"
#include "Model/Map/MapObject.h"
#include "TypeBuilding.h"

class Building: public MapObject
{
public:
	TypeBuilding* _typeBuilding;
	TypeBuilding* getTypeBuilding() const;
	void setTypeBuilding(TypeBuilding* typeBuilding);

CC_SYNTHESIZE(int, _id, Id);
	
	CREATE_FUNC(Building)
protected:
	int getFrame() const override;
};


#endif //CAPITALISM_BUILDING_H
