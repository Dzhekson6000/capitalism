#ifndef CAPITALISM_BUTTON_H
#define CAPITALISM_BUTTON_H

#include "ui/CocosGUI.h"

class Button: public cocos2d::ui::Button
{
public:
	enum class Color
	{
		BLUE,
		GREEN,
		GREY,
		RED,
		YELLOW
	};
	
	static Button* create(Color color = Color::BLUE);
private:
	bool init(Color color);
	
};


#endif //CAPITALISM_BUTTON_H
