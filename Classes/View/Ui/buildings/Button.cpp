#include "Button.h"

Button* Button::create(Button::Color color)
{
	Button *pRet = new(std::nothrow) Button();
    if (pRet && pRet->init(color))
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

bool Button::init(Button::Color color)
{
	//TODO:: пока что просто используем 1 цвет
	return cocos2d::ui::Button::init("ui/PNG/blue_button04.png", "ui/PNG/blue_button03.png");
}
