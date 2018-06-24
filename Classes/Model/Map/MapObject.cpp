#include "MapObject.h"

MapObject::MapObject():
		frame(0),
		wCell(1),
		hCell(1),
		label(nullptr),
		type(Type::NONE)
{

}

bool MapObject::initObject()
{
	std::string fileName = group + "/" + name;
	frame = getFrame();
	if( frame != 0 )
	{
		fileName += "/" + std::to_string(frame);
	}
	fileName += ".png";
	
	return Sprite::initWithSpriteFrameName(fileName);
}

void MapObject::updateIsoPoint()
{
	isoPoint.updateScreen();
	initObject();
	setPosition(isoPoint);
}

void MapObject::printDebugCell(std::string text)
{
	if(label)
	{
		removeChild(label,true);
	}
	label = Label::createWithTTF(text.c_str(), "fonts/arial.ttf", 14);
	label->setTextColor(Color4B::RED);
	label->setPositionNormalized(getAnchorPoint());
	addChild(label, 2);
}

void MapObject::removeFromLayer()
{
	groupObject->removeChild(this);
}

int MapObject::getFrame() const
{
	return frame;
}

const IsoPoint &MapObject::getIsoPoint() const
{
	return isoPoint;
}

void MapObject::setIsoPoint(const IsoPoint &isoPoint)
{
	MapObject::isoPoint = isoPoint;
	
	int local = static_cast<int>(
			(
					(300-isoPoint.getCell().x) + (isoPoint.getCell().y)
			)
	);
	
	setLocalZOrder(local);//TODO: временный хак что бы правильно рисовать по Z. могут быть косяки при большой карте
	setPosition(isoPoint);
}

MapObject::Type MapObject::getType() const
{
	return type;
}

void MapObject::setType(MapObject::Type type)
{
	MapObject::type = type;
}

const std::string &MapObject::getGroup() const
{
	return group;
}

void MapObject::setGroup(const std::string &group)
{
	MapObject::group = group;
}

const std::string &MapObject::getName() const
{
	return name;
}

void MapObject::setName(const std::string &name)
{
	MapObject::name = name;
}

Layer* MapObject::getGroupObject() const
{
	return groupObject;
}

void MapObject::setGroupObject(Layer* groupObject)
{
	MapObject::groupObject = groupObject;
}
