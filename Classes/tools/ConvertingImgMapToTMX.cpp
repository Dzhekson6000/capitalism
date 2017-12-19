#include "ConvertingImgMapToTMX.h"
#include "cocos2d.h"

USING_NS_CC;

bool ConvertingImgMapToTMX::converting(const std::string &pathIn, const std::string &pathOut)
{
	Image* imgmap = new Image();
	if( !imgmap->initWithImageFile(pathIn))
	{
		CCLOG("Не удалось открыть файл для конвертирования %s", pathIn.c_str());
		delete imgmap;
		return false;
	}
	
	int approximateSize = imgmap->getWidth()*imgmap->getHeight()*2;
	
	std::string csv;
	csv.reserve((unsigned long)approximateSize);
	
	csv = "<layer name=\"Landscape\" width=\"" + std::to_string(imgmap->getWidth())
	       + "\" height=\"" + std::to_string(imgmap->getHeight()) + "\">";
	csv += "<data encoding=\"csv\">";
	
	int countChenal;
	if( imgmap->hasAlpha())
	{
		countChenal = 4;
	}
	else
	{
		countChenal = 3;
	}
	
	int type = 0;
	
	for( int x = imgmap->getWidth() - 1; x >= 0; x-- )
	{
		for( int y = imgmap->getHeight() - 1; y >= 0; y-- )
		{
			type = *(imgmap->getData() + (x + y*imgmap->getWidth())*countChenal) + 2;
			csv += std::to_string(type);
			if( x != 0 || y != 0 )
			{
				csv += ",";
			}
		}
	}
	csv += "</data></layer>";
	
	return saveTMXFile(pathOut, csv, imgmap->getWidth(), imgmap->getHeight());
}

bool ConvertingImgMapToTMX::saveTMXFile(const std::string &pathOut, const std::string &layer, int width, int height)
{
	std::string tmxfile;
	tmxfile.reserve(layer.size() + 200);
	tmxfile = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
	tmxfile += "<map version=\"1.0\" tiledversion=\"1.0.3\" "
			           "orientation=\"isometric\" renderorder=\"right-down\" "
			           "width=\"" + std::to_string(width) + "\" height=\"" + std::to_string(height) + "\" "
			           "tilewidth=\"46\" tileheight=\"23\" nextobjectid=\"1\">";
	
	tmxfile += layer;
	tmxfile += "</map>";
	
	
	
	return FileUtils::getInstance()->writeStringToFile(
			tmxfile,
			FileUtils::getInstance()->getDefaultResourceRootPath() + pathOut
	);
}
