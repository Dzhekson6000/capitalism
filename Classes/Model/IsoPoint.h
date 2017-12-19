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
	
	cocos2d::Point getCell() const;
	
	/**
	 * @brief конвертация изометрических координат в экранные
	 * @param x изометрический X
	 * @param y изометрический Y
	 */
	void isoToScreen(float x, float y);
	/**
	 * @brief конвертация экранных координат в изометрические
	 * @param x изометрический X
	 * @param y изометрический Y
	 */
	void screenToIso(float x, float y);
	/**
	 * @brief сокращение координат до размеров клетки
	 */
	void reductionToCell();
	
	CC_SYNTHESIZE_READONLY(cocos2d::Point, _isoPoint, Original);
};


#endif //CAPITALISM_ISOPOINT_H
