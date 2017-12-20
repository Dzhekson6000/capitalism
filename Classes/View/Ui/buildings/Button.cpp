#include "Button.h"

std::vector<std::string> Button::_colors =
		                         {
				                         "blue_",
				                         "gray_",
				                         "green_",
				                         "orange_",
				                         "red_",
				                         "yellow_"
		                         };

Button* Button::create(WidgetType type, Color color)
{
	Button *pRet = new(std::nothrow) Button();
    if (pRet && pRet->_init(type, color))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        return nullptr;
    }
}

bool Button::_init(WidgetType type, Color color)
{
	LoaderSpriteSheets* spriteSheets = LoaderSpriteSheets::GetInstance();
	
	//TODO:: пока что просто используем 1 цвет
	return cocos2d::ui::Button::init(_colors[color] + "button04.png", _colors[color] + "button03.png", _colors[color] + "button04.png", TextureResType::PLIST);
}
