#ifndef CAPITALISM_CUTORIGINALATLAS_H
#define CAPITALISM_CUTORIGINALATLAS_H

#include <string>
#include "tinyxml2/tinyxml2.h"
#include "cocos2d.h"

using namespace tinyxml2;

class CutOriginalAtlas
{
public:
	static void cutFromConfig(const std::string &pathConfigFile);
private:
	
	/**
	 * парсит спрайт
	 * @param sprite xml элемент спрайта
	 * @param path путь к тайлсету
	 * @param group группа в которую нужно сохранить
	 */
	static void parserSprites(XMLElement* sprites,std::string spritesRoot);
	
	/**
	 * парсит спрайт
	 * @param sprite xml элемент спрайта
	 * @param path путь к тайлсету
	 * @param group группа в которую нужно сохранить
	 */
	static void parserSprite(XMLElement* sprite, std::string path, std::string nameGroup);
	
	/**
	 * парсит координаты тайла
	 * @param coords строка с координатам формата "0,0,46,24,23,12"
	 * @param rect размеры спрайта тайла
	 * @param vec координаты центра
	 * @return
	 */
	static bool parseCoords(std::string coords, cocos2d::Rect &rect, cocos2d::Vec2 &vec);
	
	static void saveSprite(const std::string& path, cocos2d::SpriteFrame* sf);
};


#endif //CAPITALISM_CUTORIGINALATLAS_H
