#include "Building.h"
#include "Model/Map/Camera.h"

int Building::getFrame() const
{
	/*::Camera::Direction direction = ::Camera::getInstance()->getDirection();
	
	if(direction==::Camera::Direction::SouthEast || direction==::Camera::Direction::NorthWest)
	{
		return 2;
	}
	return 1;*/
	
	return 1;
}

TypeBuilding* Building::getTypeBuilding() const
{
	return _typeBuilding;
}

void Building::setTypeBuilding(TypeBuilding* typeBuilding)
{
	_typeBuilding = typeBuilding;
	wCell = typeBuilding->width;
	hCell = typeBuilding->height;
	setGroup(typeBuilding->group);
	setName(typeBuilding->name);
}
