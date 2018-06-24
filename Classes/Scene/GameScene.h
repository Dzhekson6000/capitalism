#ifndef CAPITALISM_GAMESCENE_H
#define CAPITALISM_GAMESCENE_H

#include "cocos2d.h"
#include "Model/Map/World/World.h"
#include "Controller/KeyboardController.h"
USING_NS_CC;

/**
 * @brief класс игровой сцены
 */
class GameScene:public cocos2d::Scene
{
public:
	CREATE_FUNC(GameScene);
	static cocos2d::Scene* createScene();
	
	/**
	 * функция инициализации
	 * @return true = успешно
	 */
	bool init() override;
	
	/**
	 * инициализация вращения и приближение камеры по нажатию
	 */
	void initKeyboard();
	
	/**
	 * @brief функция обновления состояния
	 * @param delta время с последнего изменения
	 */
	void update(float delta) override;
private:
	KeyboardController keyboardController; ///< Контролер клавиатуры
	World* world; ///< мир. там карта города.
	
};


#endif //CAPITALISM_GAMESCENE_H
