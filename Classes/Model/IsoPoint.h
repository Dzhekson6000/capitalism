#ifndef CAPITALISM_ISOPOINT_H
#define CAPITALISM_ISOPOINT_H

#include "cocos2d.h"

class IsoPoint: public cocos2d::Point
{
public:
	IsoPoint();
	IsoPoint(cocos2d::Point point);
	IsoPoint(int x, int y);
	IsoPoint(float x, float y);
	
	void initOfIso(const cocos2d::Point point);
	void initOfScreen(const cocos2d::Point point);
	
	void initOfIso(const float x, const float y);
	void initOfScreen(const float x, const float y);
	
	void updateScreen();
	void updateIso();
	
	cocos2d::Point getCell() const;
	
	/**
	 * @brief сокращение координат до размеров клетки
	 */
	void reductionToCell();
	
	CC_SYNTHESIZE_READONLY(cocos2d::Point, _isoPoint, Original);
};


#endif //CAPITALISM_ISOPOINT_H
