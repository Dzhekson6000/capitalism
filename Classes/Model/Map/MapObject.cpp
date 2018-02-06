#include "MapObject.h"

MapObject::MapObject()
{
	
}

bool MapObject::initObject()
{
	std::string fileName = _group+"/"+_name;
	if(_frame!=0)
	{
		fileName+="/"+std::to_string(_frame);
	}
	fileName+=".png";
	
	return Sprite::initWithSpriteFrameName(fileName);
}

void MapObject::setIsoPoint(const IsoPoint isoPoint)
{
	_isoPoint = isoPoint;
	setLocalZOrder(10000-(isoPoint.getCell().x + isoPoint.getCell().y));//TODO: временный хак что бы правильно рисовать по Z. могут быть косяки при большой карте
	setPosition(_isoPoint);
}

void MapObject::updateIsoPoint()
{
	_isoPoint.updateScreen();
	setPosition(_isoPoint);
}

void MapObject::printDebugCell(std::string text)
{
	auto label = Label::createWithTTF(text.c_str(), "fonts/arial.ttf", 14);
	label->setTextColor(Color4B::RED);
	label->setPositionNormalized(getAnchorPoint());
	addChild(label, 2);
}
