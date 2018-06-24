#ifndef CAPITALISM_ISOSCROLLER_H
#define CAPITALISM_ISOSCROLLER_H

#include "Scroller.h"

class IsoScroller:public Scroller
{
private:
	IsoPoint _cameraPosition;
public:
	CREATE_FUNC(IsoScroller)
	bool init() override;
	
	void setPosition(const cocos2d::Vec2 &position) override;
	void setScale(float scale) override;
	virtual void updateIsoPoints();
protected:
	void onClick(const cocos2d::Point point) override;
	virtual void onClickCell(const IsoPoint &point);
	
};


#endif //CAPITALISM_ISOSCROLLER_H
