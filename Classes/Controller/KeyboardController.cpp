#include "KeyboardController.h"

KeyboardController::KeyboardController()
{
	_listener = EventListenerKeyboard::create();
	_listener->onKeyPressed  = CC_CALLBACK_2(KeyboardController::onKeyPressed, this);
	_listener->onKeyReleased = CC_CALLBACK_2(KeyboardController::onKeyReleased, this);
	
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(_listener, 100);
}

KeyboardController::~KeyboardController()
{
	Director::getInstance()->getEventDispatcher()->removeEventListener(_listener);
}

void KeyboardController::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if( _keys.find(keyCode) == _keys.end())
	{
		_keys[keyCode] = std::chrono::high_resolution_clock::now();
	}
}

void KeyboardController::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	_keys.erase(keyCode);
}

bool KeyboardController::isKeyPressed(cocos2d::EventKeyboard::KeyCode code)
{
	if( _keys.find(code) != _keys.end())
	{
		return true;
	}
	return false;
}

double KeyboardController::keyPressedDuration(cocos2d::EventKeyboard::KeyCode code)
{
	return std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::high_resolution_clock::now() - _keys[code])
			.count();
}
