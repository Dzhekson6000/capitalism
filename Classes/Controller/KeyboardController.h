#ifndef CAPITALISM_KEYBOARDCONTROLLER_H
#define CAPITALISM_KEYBOARDCONTROLLER_H

#include "cocos2d.h"

USING_NS_CC;

class KeyboardController
{
public:
	KeyboardController();
	~KeyboardController();
	
	/**
	 * @param code код кнопки
	 * @return true = кнопка нажата
	 */
	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode code);
	
	/**
	 * @param code код кнопки
	 * @return время нажатия
	 */
	double keyPressedDuration(cocos2d::EventKeyboard::KeyCode code);
	
	void addCallback(EventKeyboard::KeyCode keyCode, std::function<void()> func);
	void removeCallback(EventKeyboard::KeyCode keyCode, std::function<void()> func);
private:
	EventListenerKeyboard* _listener;
	std::map<EventKeyboard::KeyCode, std::chrono::high_resolution_clock::time_point> _keys;
	std::unordered_multimap<EventKeyboard::KeyCode, std::function<void()>> _keysCallback;
	
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};


#endif //CAPITALISM_KEYBOARDCONTROLLER_H
