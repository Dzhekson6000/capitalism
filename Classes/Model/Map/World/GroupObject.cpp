#include "GroupObject.h"
#include "tools/IsoTools.h"

GroupObject::GroupObject()
{
}

void GroupObject::addObject(MapObject* object)
{
	GroupObject* groupObject = getGroupObject(object->getIsoPoint().getOriginal());
	object->setGroupObject(groupObject);
	groupObject->addChild(object);
}

void GroupObject::updateInvisible(const IsoScroller& isoScroller)
{
	if( !isVisible(isoScroller.getPosition(),isoScroller.getScale()))
	{
		setVisible(false);
	}
	else
	{
		setVisible(true);
		if(
				!(_size.width <= IsoTools::getNumberOfCell(10) &&
				  _size.height <= IsoTools::getNumberOfCell(10))
				)
		{
			for( auto groupObject: getChildren())
			{
				GroupObject* group = (GroupObject*)groupObject;
				group->updateInvisible(isoScroller);
			}
		}
		
	}
	
}

GroupObject* GroupObject::findGroupObject(Point cell)
{
	if(
			_size.width < IsoTools::getNumberOfCell(10) &&
			_size.height < IsoTools::getNumberOfCell(10)
			)
	{
		return this;
	}
	
	GroupObject* subGroup = findSubGroupObject(cell);
	if( subGroup )
	{
		return subGroup->findGroupObject(cell);
	}
	return nullptr;
}

void GroupObject::updateIsoPoints()
{
	if(
			_size.width <= IsoTools::getNumberOfCell(10) &&
			_size.height <= IsoTools::getNumberOfCell(10)
			)
	{//это листок дерева
		
		for( auto mapObject: getChildren())//перебираем все тайлы и объекты карты
		{
			MapObject* object = (MapObject*)mapObject;
			object->updateIsoPoint();
		}
	}
	else
	{//это узел дерева, нужно рекурсивно спуститься к листьям
		for( auto groupObject: getChildren())
		{
			((GroupObject*)groupObject)->updateIsoPoints();
		}
	}
	
	_isoPoint.updateScreen();
}

GroupObject* GroupObject::findSubGroupObject(Point point)
{
	for( auto groupObject: getChildren())
	{
		GroupObject* group = (GroupObject*)groupObject;
		if( group->isBoundingBoxCell(point))
		{
			return group;
		}
	}
	return nullptr;
}

bool GroupObject::isVisible(const Point point, const float zoom) const
{
	auto size = Director::getInstance()->getWinSize();
	
	//Screen:
	/* A ****** B
	 * * ****** *
	 * * ****** *
	 * * ****** *
	 * C ****** D*/
	
	IsoPoint pointA;
	IsoPoint pointB;
	IsoPoint pointC;
	IsoPoint pointD;
	
	pointA.initOfScreen(
			-point.x/zoom,
			-point.y/zoom + size.height/zoom
	
	);
	pointB.initOfScreen(
			-point.x/zoom + size.width/zoom,
			-point.y/zoom + size.height/zoom
	
	);
	pointC.initOfScreen(-point/zoom);
	pointD.initOfScreen(
			-point.x/zoom + size.width/zoom,
			-point.y/zoom
	);
	
	auto resultX = std::minmax(
			{
					pointA.getOriginal().x,
					pointB.getOriginal().x,
					pointC.getOriginal().x,
					pointD.getOriginal().x
			});
	auto resultY = std::minmax(
			{
					pointA.getOriginal().y,
					pointB.getOriginal().y,
					pointC.getOriginal().y,
					pointD.getOriginal().y
			});
	
	if(_isoPoint.getOriginal().x > resultX.second)
	{
		return false;
	}
	if(_isoPoint.getOriginal().x + _size.width < resultX.first)
	{
		return false;
	}
	
	if(_isoPoint.getOriginal().y > resultY.second)
	{
		return false;
	}
	if(_isoPoint.getOriginal().y + _size.height < resultY.first)
	{
		return false;
	}
	
	
	
	return true;
}

bool GroupObject::isBoundingBoxCell(const Point point) const
{
	Point isoPoint = _isoPoint.getOriginal();
	
	return !(point.x < isoPoint.x ||
	         point.y < isoPoint.y ||
	         point.x > isoPoint.x + _size.width ||
	         point.y > isoPoint.y + _size.height);
}

GroupObject* GroupObject::getGroupObject(Point cell)
{
	if(
			_size.width <= IsoTools::getNumberOfCell(10) &&
			_size.height <= IsoTools::getNumberOfCell(10)
			)
	{
		return this;
	}
	GroupObject* subGroup = findSubGroupObject(cell);
	if( subGroup )
	{
		return subGroup->getGroupObject(cell);
	}
	return createGroupObject(cell);
}

GroupObject* GroupObject::createGroupObject(Point point)
{
	if(
			_size.width <= IsoTools::getNumberOfCell(10) &&
			_size.height <= IsoTools::getNumberOfCell(10)
			)
	{
		return this;
	}
	
	GroupObject* subGroup = findSubGroupObject(point);
	if( subGroup )
	{
		return subGroup->createGroupObject(point);
	}
	
	if(
			point.x > _size.width + _isoPoint.getOriginal().x ||
			point.y > _size.height + _isoPoint.getOriginal().y
			)
	{
		return nullptr;
	}
	
	Size subGroupSize;
	subGroupSize.width  = _size.width/10;
	subGroupSize.height = _size.height/10;
	
	IsoPoint isoPoint;
	isoPoint.initOfIso(
			floor(point.x/subGroupSize.width)*subGroupSize.width,
			floor(point.y/subGroupSize.height)*subGroupSize.height
	);
	
	GroupObject* newGroupObject = GroupObject::create();
	newGroupObject->setSizeGroup(subGroupSize);
	newGroupObject->setIsoPoint(isoPoint);
	addChild(newGroupObject);
	return newGroupObject->createGroupObject(point);
	
}

void GroupObject::setIsoPoint(const IsoPoint &isoPoint)
{
	_isoPoint = isoPoint;
	int local = static_cast<int>(
			(
					(300-_isoPoint.getCell().x) + (_isoPoint.getCell().y)//TODO:надо фиксить
			)
	);
	setLocalZOrder(local);
}
