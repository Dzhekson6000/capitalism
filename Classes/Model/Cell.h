#ifndef CAPITALISM_CELL_H
#define CAPITALISM_CELL_H

#include <string>
#include <unordered_map>
#include "cocos2d.h"
#include "Model/IsoPoint.h"
#include "MapCity.h"

USING_NS_CC;

class Cell:public Sprite
{
public:
	
	virtual bool initTile();
	void setIsoPoint(const IsoPoint isoPoint);
	
	static std::string getNameCellOfPixel(const unsigned char* pixel);
	static std::string getNameCellOfType(const int type);
private:
	static const std::unordered_map<int, std::string> _cellsName;
	
	int getTypeOffset(int x, int y);
	
CC_SYNTHESIZE_READONLY(IsoPoint, _isoPoint, IsoPoint);
CC_SYNTHESIZE(int , _type, Type);
CC_SYNTHESIZE(MapCity*, _map, Map);

CREATE_FUNC(Cell)

protected:
	virtual int getFrame();
	virtual bool checkSameType(int x, int y);
	Cell();
	
	void printDebugCell(std::string text);
};


#endif //CAPITALISM_CELL_H
