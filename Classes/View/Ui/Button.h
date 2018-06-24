#ifndef CAPITALISM_BUTTON_H
#define CAPITALISM_BUTTON_H

#include "ui/CocosGUI.h"
#include "Loader/LoaderSpriteSheets.h"

#include <vector>

class Button: public cocos2d::ui::Button
{
public:
	enum Color
	{
		BLUE = 0,
		GRAY = 1,
		GREEN = 2,
		OGANGE = 3,
		RED = 4,
		YELLOW = 5
	};
	
	enum class WidgetType
	{
		BUTTON,
		CHECKMARK,
		CROSS,
		TICK,
		CIRCLE,
		PANEL,
		SLIDERDOWN,
		SLIDERLEFT,
		SLIDERRIGHT,
		SLIDERUP
	};
	static Button* create(WidgetType type = WidgetType::BUTTON, Color color = Color::BLUE);
private:
	static std::vector<std::string> _colors;
private:
	bool _init(WidgetType type, Color color);
};


#endif //CAPITALISM_BUTTON_H
