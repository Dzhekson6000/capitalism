#ifndef CAPITALISM_GAMESCENE_H
#define CAPITALISM_GAMESCENE_H

#include "cocos2d.h"
#include "Model/Map/World.h"
#include "Controller/KeyboardController.h"
USING_NS_CC;

/**
 * @brief класс игровой сцены
 */
class GameScene:public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	
	/**
	 * функция инициализации
	 * @return true = успешно
	 */
	virtual bool init();
		
	CREATE_FUNC(GameScene);
	
	/**
	 * @brief функция обновления состояния
	 * @param delta время с последнего изменения
	 */
	void update(float delta) override;
private:
	KeyboardController _keyboardController; ///< Контролер клавиатуры
	World* _world; ///< мир. там карта города.
	
};


#endif //CAPITALISM_GAMESCENE_H
