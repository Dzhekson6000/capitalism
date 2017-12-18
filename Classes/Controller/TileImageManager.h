#ifndef CAPITALISM_IMAGEMANAGER_H
#define CAPITALISM_IMAGEMANAGER_H

#include <string>
#include <vector>
#include <unordered_map>
#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"

using namespace tinyxml2;

class TileImageManager
{
public:
	static TileImageManager* getInstance();
	
	/**
	 * структурка для тайлов
	 */
	struct SpriteItem
	{
		std::vector<cocos2d::SpriteFrame*> frames;
	};
	
	/**
	 * структурка для хранения групп тайлов
	 */
	struct Group
	{
		std::unordered_map<std::string, SpriteItem*> sprites;
	};
	
	typedef std::unordered_map<std::string, Group*> GroupsType;
	
	/**
	 * парсит группы
	 * @param sprites xml элемент группы
	 */
	void parserSprites(XMLElement* sprites);
	
	/**
	 * Возвращает фрейм
	 * @param group группа тайла
	 * @param sprite имя тайла
	 * @param frame номер фрейма
	 * @return
	 */
	cocos2d::SpriteFrame* getFrame(std::string group, std::string sprite, int frame = 0);
private:
	static TileImageManager* _imageManager;
	
	TileImageManager();
	~TileImageManager();
	
	/**
	 * парсит спрайт
	 * @param sprite xml элемент спрайта
	 * @param path путь к тайлсету
	 * @param group группа в которую нужно сохранить
	 */
	void parserSprite(XMLElement* sprite, std::string &path, Group* group);
	
	/**
	 * парсит координаты тайла
	 * @param coords строка с координатам формата "0,0,46,24,23,12"
	 * @param rect размеры спрайта тайла
	 * @param vec координаты центра
	 * @return
	 */
	bool parseCoords(std::string coords, cocos2d::Rect &rect, cocos2d::Vec2 &vec);
	
	/**
	 * выгружает все хранимые изображения
	 */
	void releaseImage();

CC_SYNTHESIZE(std::string, _spritesRoot, SpritesRoot);
CC_SYNTHESIZE_READONLY(GroupsType, _groups, Groups);
};


#endif //CAPITALISM_IMAGEMANAGER_H
