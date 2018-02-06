#ifndef CAPITALISM_ISOSCROLLER_H
#define CAPITALISM_ISOSCROLLER_H

#include "Scroller.h"

class IsoScroller: public Scroller
{
private:
	IsoPoint _cameraPosition;
public:
	CREATE_FUNC(IsoScroller)
	
	void setPosition(const cocos2d::Vec2 &position) override;
	
	virtual void updateIsoPoints();
	bool init() override;
	
	
};


#endif //CAPITALISM_ISOSCROLLER_H
